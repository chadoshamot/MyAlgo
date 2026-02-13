"""
题目背景
本题是高精度加法的模板题。

题目描述
给定两个非负整数 a,b，求它们的和。不用考虑负数。

输入格式
输入共两行，每行一个非负整数，分别为 a,b。

输出格式
输出一行一个非负整数，表示 a+b 的值
"""
a = input().strip()
b = input().strip()

a = a[::-1]
b = b[::-1]

if(len(a) < len(b)):
    a, b = b, a
    
bit = 0
ans = []    

for i in range(len(a)):
    numa = int(a[i])
    numb = int(b[i]) if i < len(b) else 0
    #add
    num = numa + numb + bit
    ans.append(str(num % 10))
    bit = num // 10

if bit > 0:
    ans.append(str(bit))
    
ans = ans[::-1]
print (''.join(ans))