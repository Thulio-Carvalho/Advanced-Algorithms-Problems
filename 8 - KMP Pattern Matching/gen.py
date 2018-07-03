from sys import stdout
for i in range(10000000):
    stdout.write("A")
stdout.write("\n")
stdout.flush()