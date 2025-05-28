from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from tgoogle.auth.transport.requests import Request
from googleapiclient.discovery import build
import pickle
import os
# Define the scopes
SCOPES = ['https://www.googleapis.com/auth/drive.readonly']
from langchain.llms import Cohere
from langchain.prompts import PromptTemplate
from langchain_community.document_loaders import TextLoader
import os
from googleapiclient.discovery import build
from googleapiclient.http import MediaIoBaseDownload
import io

# Set up Cohere
COHERE_API_KEY = "95Tqis8eCp2oR13txgUmQIlEgpibBl3TrR49T0e1"
os.environ["COHERE_API_KEY"] = COHERE_API_KEY

def download_file_from_drive(file_id, creds):
    """Download a file from Google Drive"""
    try:
        # Create Drive API service
        service = build('drive', 'v3', credentials=creds)

        # Get the file
        request = service.files().get_media(fileId=file_id)
        file = io.BytesIO()
        downloader = MediaIoBaseDownload(file, request)

        done = False
        while done is False:
            status, done = downloader.next_chunk()

        return file.getvalue().decode('utf-8')

    except Exception as e:
        print(f"Error downloading file: {e}")
        return None

def process_text(text):
    """Process text using LangChain and Cohere"""
    # Initialize Cohere
    llm = Cohere()

    # Create prompt template
    prompt_template = PromptTemplate(
        input_variables=["text"],
        template="""
        Analyze the following text and provide:
        1. Main themes
        2. Key points
        3. Brief summary

        Text: {text}
        """
    )

    # Generate the prompt
    prompt = prompt_template.format(text=text)

    # Get response
    return llm(prompt)




# def get_google_drive_creds():
#     creds = None
#     # Check if token.pickle exists
#     if os.path.exists('token.pickle'):
#         with open('token.pickle', 'rb') as token:
#             creds = pickle.load(token)

#     # If credentials are invalid or don't exist
#     if not creds or not creds.valid:
#         if creds and creds.expired and creds.refresh_token:
#             creds.refresh(Request())
#         else:
#             # Provide the full path to your credentials.json file if it's not in the same directory
#             flow = InstalledAppFlow.from_client_secrets_file(
#                 'credentials.json', # or 'path/to/your/credentials.json'
#                 SCOPES)
#             creds = flow.run_local_server(port=0)

#         # Save credentials
#         with open('token.pickle', 'wb') as token:
#             pickle.dump(creds, token)

#     return creds

def main():
    # Get Google Drive credentials
    creds = get_google_drive_creds()

    # Your Google Drive file ID
    file_id = "https://docs.google.com/document/d/1Lf3MP54yWP_ZEx871aJimw3-4PgDCK66/edit?usp=drive_web&ouid=110652516482606033027&rtpof=true"

    # Download the file
    text_content = download_file_from_drive(file_id, creds)

    if text_content:
        # Process the text
        result = process_text(text_content)
        print(result)
    else:
        print("Failed to download file")
        if __name__ == "__main__":
          main()
import os
os.listdir('.')
