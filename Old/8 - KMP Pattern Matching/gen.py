from sys import stdout
for i in range(1000000):
    stdout.write("A")
stdout.write("\n")
stdout.flush()
