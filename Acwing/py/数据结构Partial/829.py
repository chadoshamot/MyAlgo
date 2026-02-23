from collections import deque

que = deque()

def push(x):
    que.append(x)
    
def pop():
    que.popleft()
    
def empty():
    return len(que) == 0

def query(): 
    if not empty(): 
        return que[0]
    else:
        return -1
    
m = int(input().strip())

for i in range(m):
    op = list(map(str, input().strip().split()))
    if op[0] == "push":
        num = int(op[1])
        push(num)
    if op[0] == "pop":
        pop()
    if op[0] == "empty":
        ret = empty()
        if ret:
            print("YES")
        else:
            print("NO")
    if op[0] == "query":
        print(query())