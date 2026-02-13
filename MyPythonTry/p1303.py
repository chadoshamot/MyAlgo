"""
题目背景
高精度乘法模板题。

题目描述
给出两个非负整数，求它们的乘积。

输入格式
输入共两行，每行一个非负整数。

输出格式
输出一个非负整数表示乘积。
"""

a = input().strip()
b = input().strip()

if len(a) < len(b):
    a, b = b, a

c = [0] * (len(a) + len(b))

a = a[::-1]
b = b[::-1]

for i in range(len(a)):
    for j in range(len(b)):
        c[i + j] += (int)(a[i]) * (int)(b[j])

ans = []
carry = 0



for i in range(len(c)):
    num = (c[i] + carry) % 10
    ans.append(str(num))
    carry = (c[i] + carry) // 10
    
# for i in range(len(ans)):
#     print(ans[i])

ansStr = ''.join(ans[::-1]).lstrip('0')
if not ansStr:
    ansStr = '0'
print(ansStr)
