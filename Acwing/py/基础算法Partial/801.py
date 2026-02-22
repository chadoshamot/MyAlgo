def calc(num):
    cnt = 0
    while num > 0:
        pre = num
        num = num & (num - 1)
        if pre != num:
            cnt += 1
    return cnt

n = int(input().strip())
a = list(map(int, input().strip().split()))
ans = []
for i in range(n):
    num = calc(a[i])
    ans.append(str(num))

print(' '.join(ans))
