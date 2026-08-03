import subprocess

def tts(text):
    subprocess.run(["espeak", text])

# changed this because it is offensive
tts("I like cheese")