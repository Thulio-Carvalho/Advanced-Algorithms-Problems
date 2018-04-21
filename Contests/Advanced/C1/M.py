n = int(raw_input())
arr = map(int, raw_input().split())

prog = True
dif = arr[1] - arr[0]
for i in xrange(len(arr)-1):
    if ((arr[i+1] - arr[i]) != dif):
        prog = False
        break
if prog:
    print arr[n-1] + dif
else: print arr[n-1]
