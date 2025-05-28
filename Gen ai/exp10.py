!pip install PyPDF2
!pip install langchain
!pip install faiss-cpu
!pip install streamlit
!pip install langchain_community
!pip install huggingface_hub
!pip install langchain-together
import os
import PyPDF2
from langchain.text_splitter import RecursiveCharacterTextSplitter
from langchain.vectorstores import FAISS
from langchain.embeddings import HuggingFaceEmbeddings
from langchain.chains import ConversationalRetrievalChain
from langchain.memory import ConversationBufferMemory
from langchain.prompts import PromptTemplate
from langchain_together import Together
import streamlit as st

# 1. Download and Process the Indian Penal Code Document
# Assuming you have the PDF file 'Indian_Penal_Code.pdf' in the same directory

def load_and_process_pdf(pdf_path="Indian Penal Code.pdf"):
    with open(pdf_path, "rb") as pdf_file:
        pdf_reader = PyPDF2.PdfReader(pdf_file)
        text = ""
        for page in pdf_reader.pages:
            text += page.extract_text()

    text_splitter = RecursiveCharacterTextSplitter(chunk_size=1000, chunk_overlap=200)
    chunks = text_splitter.split_text(text)
    return chunks

# 2. Create Embeddings and Vector Store
def create_vector_store(text_chunks):
    embeddings = HuggingFaceEmbeddings(model_name="nomic-ai/nomic-embed-text-v1", model_kwargs={"trust_remote_code": True, "revision": "289f532e14dbbbd5a04753fa58739e9ba766f3c7"})
    vector_store = FAISS.from_texts(text_chunks, embeddings)
    return vector_store

# 3. Build a Conversational Retrieval Chain
def build_chatbot(vector_store):

    prompt_template = """<s>[INST]This is a chat template and As a legal chat bot specializing in Indian Penal Code queries, your primary objective is to provide accurate and concise information based on the user's questions.
    Also mention the act and section numbers according to IPC. Do not generate your own questions and answers. You will adhere strictly to the instructions provided, offering relevant context from the knowledge base while avoiding unnecessary details. Your responses will be brief, to the point, and in compliance with the established format. If a question falls outside the given context, you will refrain from utilizing the chat history and instead rely on your own knowledge base to generate an appropriate response. You will prioritize the user's query and refrain from posing additional questions. The aim is to deliver professional, precise, and contextually relevant information pertaining to the Indian Penal Code.
    CONTEXT: {context}
    CHAT HISTORY: {chat_history}
    QUESTION: {question}
    ANSWER:
    </s>[INST]
    """
    prompt = PromptTemplate(template=prompt_template, input_variables=['context', 'question', 'chat_history'])

    llm = Together(
        model="mistralai/Mistral-7B-Instruct-v0.2",
        temperature=0.5,
        max_tokens=1024,
        together_api_key="YOUR_TOGETHER_API_KEY" # Replace with your actual key
    )

    memory = ConversationBufferMemory(memory_key="chat_history", return_messages=True)

    qa = ConversationalRetrievalChain.from_llm(
        llm=llm,
        retriever=vector_store.as_retriever(),
        memory=memory,
        combine_docs_chain_kwargs={'prompt': prompt}
    )
    return qa

# --- Streamlit App ---
st.title("Indian Penal Code Chatbot")

if "messages" not in st.session_state:
    st.session_state.messages = []

# Initialization on first run
if "qa" not in st.session_state:
    with st.spinner("Initializing chatbot..."):
        text_chunks = load_and_process_pdf()
        vector_store = create_vector_store(text_chunks)
        st.session_state.qa = build_chatbot(vector_store)
        st.success("Chatbot initialized!")

# Chat interface
for message in st.session_state.messages:
    with st.chat_message(message["role"]):
        st.markdown(message["content"])

if prompt := st.chat_input("Enter your question about the Indian Penal Code:"):
    st.session_state.messages.append({"role": "user", "content": prompt})
    with st.chat_message("user"):
        st.markdown(prompt)

    with st.chat_message("assistant"):
        with st.spinner("Thinking..."):
            response = st.session_state.qa({"question": prompt})
            st.session_state.messages.append({"role": "assistant", "content": response['answer']})
            st.markdown(response['answer'])
