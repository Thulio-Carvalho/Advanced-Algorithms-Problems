n = int(input())
ans = ""
cnt = 0
b = False
for i in range(n):
    if (cnt == 2):
        b = not b
        cnt = 0
    if(b):
        ans += "b"
    else: ans += "a"
    cnt += 1

print(ans)
