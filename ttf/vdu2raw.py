from sys import stdin, stdout


data = stdin.buffer.read()

raw = []
for index, byte in enumerate(data):
    if index % 10 not in [0, 1]:
        raw.append(byte);

stdout.buffer.write(bytes(raw))
