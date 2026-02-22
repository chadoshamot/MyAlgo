def union(vocab):
    j = 0
    sz = len(vocab)
    for i in range(sz):
        if i == 0:
            vocab[j] = vocab[i]
            j += 1
        elif vocab[i] != vocab[i - 1]:
            vocab[j] = vocab[i]
            j += 1
    return j



n, m = map(int, input().strip().split())

vocab = [0 for _ in range(300010)]
add = []
query = []

for i in range(n):
    x, c = map(int, input().strip().split())
    add.append((x, c))
    vocab.append(x)

for i in range(m):
    l, r = map(int, input().strip().split())
    query.append((l, r))
    vocab.append(l)
    vocab.append(r)
    
vocab.sort()
index = union(vocab)
vocab = vocab[0:index]

def find(x):
    l = 0
    r = len(vocab) - 1
    while l <= r:
        mid = l + (r - l) // 2
        if vocab[mid] == x:
            return mid
        elif(vocab[mid] > x):
            r = mid - 1
        else:
            l = mid + 1
    return -1

a = [0 for _ in range(300010)]
pre = [0 for _ in range(300010)]
for i in range(n):
    pair = add[i]
    x = pair[0]
    c = pair[1]
    x = find(x)
    a[x] += c
    
for i in range(1, 300010):
    pre[i] = pre[i - 1] + a[i]
    
ans = []    
for i in range(m):
    pair = query[i]
    l = find(pair[0])
    r = find(pair[1])
    num = pre[r]
    if l > 0:
        num = pre[r] - pre[l - 1]
    #ans.append(str(num))
    print(num)
    
#print(' '.join(ans))