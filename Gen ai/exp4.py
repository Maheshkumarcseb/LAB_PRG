import gensim.downloader as api

# Load the pre-trained word2Vec model (Google News or any other model you prefer)
word_vectors = api.load("word2vec-google-news-300")

# Function to get similar words
def get_similar_words(word, topn=5):
    similar_words = word_vectors.most
  original_prompt = "What are the latest advancements in technology?"

!pip install openai==0.27.0

import openai

# Initialize OpenAI API key (make sure to set your API key here)
openai.api_key = 'YOUR_API_KEY'

def generate_response(prompt):
    """Generates a response using the OpenAI API.

    Args:
        prompt: The input prompt for the model.

    Returns:
        The generated text response.
    """
    response = openai.Completion.create(
        engine="text-davinci-003",  # or any other suitable engine
        prompt=prompt,
        max_tokens=150,
        temperature=0.7
    )
    return response.choices[0].text.strip()  # Extract and return the text response
