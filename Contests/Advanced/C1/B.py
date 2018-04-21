n = int(raw_input())
arr = map(int, raw_input().split())
used = [0] * n
merged = []

unused = 0
k = 0

while (True):
    foundUnused = False
    for i in xrange(n):
        if(not used[i]):
            unused = i
            foundUnused = True
            break
    if not foundUnused: break
    merged.append([])
    merged[k].append(arr[unused])
    for i in xrange(unused, n):
        if((not used[i]) and arr[i] > merged[k][len(merged[k])-1]):
            merged[k].append(arr[i])
            used[i] = True
    k += 1


for i in xrange(k+1):
    ans = ''
    for j in xrange(len(merged[k])):
        if j == len(merged[k]-1):
            ans += str(merged[k][j])
        else:
            ans += str(merged[k][j]) + " "
    print ans
