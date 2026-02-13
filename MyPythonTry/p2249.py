"""
题目描述
输入 n 个不超过 10^9的单调不减的（就是后面的数字不小于前面的数字）非负整数 a1​,a 2​,…,a n，
然后进行 m 次询问。对于每次询问，给出一个整数 q，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出 −1 。

输入格式
第一行 2 个整数 n 和 m，表示数字个数和询问次数。

第二行 n 个整数，表示这些待查询的数字。

第三行 m 个整数，表示询问这些数字的编号，从 1 开始编号。

输出格式
输出一行，m 个整数，以空格隔开，表示答案。
"""

def split(a, num):
    l = 0
    r = len(a) - 1
    id = -1
    while l <= r:
        mid = (l + r) // 2
        if a[mid] > num:
            r = mid - 1
        elif a[mid] < num:
            l = mid + 1
        elif a[mid] == num:
            id = mid
            r = mid - 1
    return id
            

n, m = map(int, input().strip().split())

a = list(map(int, input().strip().split()))
query = list(map(int, input().strip().split()))

response = []

for i in range(len(query)):
    num = query[i]
    ans = split(a, num)
    if ans != -1:
        ans += 1
    response.append(str(ans))
    
print(' '.join(response))