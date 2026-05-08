from fastapi import FastAPI, Request
from pydantic import BaseModel
from transformers import T5ForConditionalGeneration, T5Tokenizer
import torch
import re 
from fastapi.templating import Jinja2Templates # UI
from fastapi.responses import HTMLResponse
from fastapi.staticfiles import StaticFiles

app = FastAPI(title="Text Summarizer App", description="Text Summarization using T5", version="1.0")

model = T5ForConditionalGeneration.from_pretrained("./final_t5_model")
tokenizer = T5Tokenizer.from_pretrained("./final_t5_model")

# device
if torch.backends.mps.is_available():
    device = torch.device("mps")
elif torch.cuda.is_available():
    device = torch.device("cuda")
else:
    device = torch.device("cpu")

model.to(device)

templates = Jinja2Templates(directory=".")

class DialogueInput(BaseModel):
    dialogue: str

def clean_data(text):
    text = re.sub(r"\r\n", " ", text)
    text = re.sub(r"\s+", " ", text)
    text = re.sub(r"<.*?>", " ", text)
    text = text.strip()        # ← .lower() সরিয়ে দাও
    return text

def summarize_dialogue(dialogue: str) -> str:
    dialogue = clean_data(dialogue)
    dialogue = "summarize: " + dialogue  # prefix

    print("INPUT:", dialogue[:100])  # ← যোগ করো

    inputs = tokenizer(
        dialogue,
        padding="max_length",
        max_length=512,
        truncation=True,
        return_tensors="pt"
    ).to(device)

    model.to(device)
    targets = model.generate(
        input_ids=inputs["input_ids"],
        attention_mask=inputs["attention_mask"],
        max_length=150,
        num_beams=4,
        early_stopping=True,
        use_cache=True
    )

    summary = tokenizer.decode(targets[0], skip_special_tokens=True)
    print("SUMMARY:", summary)  # ← যোগ করো
    return summary
# API endpoints
@app.get("/", response_class=HTMLResponse)
async def home(request: Request):
    return templates.TemplateResponse(request, "index.html")


@app.post("/summarize/")
async def summarize(input_data: DialogueInput):
    dialogue = input_data.dialogue
    summary = summarize_dialogue(dialogue)
    return {"summary": summary}
#uvicorn app:app --reload