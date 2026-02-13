"""
题目描述
输入两个整数 a,b，输出它们的商。

输入格式
两行，第一行是被除数，第二行是除数。

输出格式
一行，商的整数部分。
"""

a = input().strip()
b = input().strip()

r = 0
num = 0

for i in range(len(b)):
    num = num * 10 + int(b[i])
# 123 / 10

ans = []

for i in range(len(a)):
    r = r * 10 + int(a[i])
    div = r // num
    r = r % num
    ans.append(str(div))

# 0 1 2 r = 3

ansStr = ''.join(ans).lstrip('0')
if not ansStr:
    ansStr = '0'

print(ansStr)