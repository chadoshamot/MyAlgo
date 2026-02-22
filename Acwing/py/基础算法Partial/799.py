n = int(input().strip())

a = list(map(int, input().strip().split()))
cnt = [0 for _ in range(100002)]

j = 0
ans = 0

for i in range(n):
    cnt[a[i]] += 1
    while j <= i and cnt[a[i]] > 1:
        cnt[a[j]] -= 1
        j += 1
    ans = ans if ans > (i - j + 1) else (i - j + 1)

print(ans)