N, R = map(int, raw_input().split())
R = map(int, raw_input().split())
R.sort()
ans = []
print R
for i in xrange(len(R)):
    print i+1
    if i+1 != R[i]: ans.append(i+1)

strAns = ''
for i in xrange(len(ans)):
    if i != len(ans) - 1:
        strAns += str(i) + ' '
    else:
        strAns += str(i)

print strAns
