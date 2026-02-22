def calc(x1, y1, x2, y2, b, c):
    b[x1][y1] += c
    b[x2 + 1][y1] -= c
    b[x1][y2 + 1] -= c
    b[x2 + 1][y2 + 1] += c

n, m, q = map(int, input().strip().split())

a = []

for i in range(n):
    cur = list(map(int, input().strip().split()))
    a.append(cur)

b = [[0 for _ in range(m + 2)] for _ in range(n + 2)]

for i in range(n):
    for j in range(m):
        calc(i + 1, j + 1, i + 1, j + 1, b, a[i][j])
        
for i in range(q):
    x1, y1, x2, y2, c = map(int, input().strip().split())
    calc(x1, y1, x2, y2, b, c)

a = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, m + 1):
        # for a in (i, j)
        a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j]
        print(a[i][j], end = ' ')
    print()