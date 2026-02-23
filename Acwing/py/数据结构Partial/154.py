from collections import deque

n, k = map(int, input().strip().split())
a = list(map(int, input().strip().split()))

que = deque()

for i in range(k):
    while que and a[que[-1]] > a[i]:
        que.pop()
    que.append(i)
    
# ans = []

# ans.append(str(a[que[0]]))
ans = [str(a[que[0]])]

for j in range(n - k):
    i = j + k
    if que and j >= que[0]:
        que.popleft()
        
    while que and a[que[-1]] > a[i]:
        que.pop()
    que.append(i)
    ans.append(str(a[que[0]]))
    
print(' '.join(ans))

# ansbig = []
bigque = deque()

for i in range(k):
    while bigque and a[bigque[-1]] < a[i]:
        bigque.pop()
    bigque.append(i)
    
# ansbig.append(str(a[bigque[0]]))
ansbig = [str(a[bigque[0]])]

for j in range(n - k):
    i = j + k
    if bigque and j >= bigque[0]:
        bigque.popleft()
    while bigque and a[bigque[-1]] < a[i]:
        bigque.pop()
    bigque.append(i)
    ansbig.append(str(a[bigque[0]]))
    
print(' '.join(ansbig))