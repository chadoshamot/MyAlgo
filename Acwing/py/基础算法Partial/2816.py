n, m = map(int, input().strip().split())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))

a_index = 0
b_index = 0

while a_index < n and b_index < m:
    if a[a_index] == b[b_index]:
        a_index += 1
        b_index += 1
    else:
        b_index += 1
        
if a_index == n:
    print("Yes")
else:
    print("No")