n, m = map(int, input().strip().split())
vec = list(map(int, input().strip().split()))
prefix = [0] * len(vec)

prefix[0] = vec[0]

for i in range(len(vec)):
    prefix[i] = prefix[i - 1] + vec[i]

for i in range(m):
    l, r = map(int, input().strip().split())
    if l == 1:
        print(prefix[r - 1])
    else:
        print(prefix[r - 1] - prefix[l - 2])