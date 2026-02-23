sta = []

n = int(input().strip())

a = list(map(int, input().strip().split()))
ans = []
for i in range(len(a)):
    while len(sta) > 0 and sta[-1] >= a[i]:
        sta.pop()
    if len(sta) == 0:
        ans.append("-1")
    else:
        ans.append(str(sta[-1]))
    sta.append(a[i])
print(' '.join(ans))