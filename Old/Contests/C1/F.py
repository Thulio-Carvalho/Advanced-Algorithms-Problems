n = int(input())
cnt = 0
for i in range(n):
    entry = input()
    if entry == "Tetrahedron": cnt += 4
    elif entry == "Cube": cnt += 6
    elif entry == "Octahedron": cnt += 8
    elif entry == "Dodecahedron": cnt += 12
    elif entry == "Icosahedron": cnt += 20

print(cnt)
