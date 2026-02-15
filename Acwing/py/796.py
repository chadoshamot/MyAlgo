def cnt(num, n, m, prefix):
    for i in range(n + 1):
        if i == 0: continue
        for j in range(m + 1):
            if j == 0: continue
            prefix[i][j] = num[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]

n, m, q = map(int, input().strip().split())

num = []
prefix = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

for i in range(n):
    cur = list(list(map(int, input().strip().split())))
    num.append(cur)

cnt(num, n, m, prefix)

for i in range(q):
    x1, y1, x2, y2 = map(int, input().strip().split())
    ans = 0
    ans = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]
    print(ans)