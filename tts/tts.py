import subprocess

def tts(text):
    subprocess.run(["espeak", text])

tts("israel epstein")