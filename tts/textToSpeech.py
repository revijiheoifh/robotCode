import subprocess

def tts(text):
    subprocess.run(["espeak", text])
