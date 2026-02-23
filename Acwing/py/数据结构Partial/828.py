a = [0 for _ in range(100010)]
size = 0
def push(x):
    global size
    a[size] = x
    size += 1
    return

def pop():
    global size
    ret = a[size - 1]
    size -= 1
    return ret

def empty():
    global size
    return size == 0

def query():
    global size
    if size == 0:
        return -1
    else:
        return a[size - 1]
    
m = int(input().strip())
for i in range(m):
    s = list(map(str, input().strip().split()))
    if s[0] == "push":
        num = int(s[1])
        push(num)
    if s[0] == "query":
        print(query())
    if s[0] == "pop":
        pop()
    if s[0] == "empty":
        ret = empty()
        if ret:
            print("YES")
        else:
            print("NO")