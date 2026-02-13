"""
题目描述
给定两个正整数 a,b，求 a−b 的值。

输入格式
输入共两行，每行一个正整数，分别为 a,b。

输出格式
输出一行一个整数，表示 a−b 的值。

如果 a−b<0，请输出负号。
"""
a = input().strip()
b = input().strip()



flag = 0

if len(a) < len(b):
    a, b = b, a
    flag = 1

if len(a) == len(b):
    for i in range(len(a)):
        numa = int(a[i])
        numb = int(b[i]) if i < len(b) else 0
        if numa > numb:
            break
        elif numa < numb:
            a, b = b, a
            flag = 1
            break
# print("flag ==", flag)
# 3 2 1 
# 4 7 0
a = a[::-1]
b = b[::-1]

borrow = 0
ans = []

for i in range(len(a)):
    numa = int(a[i])
    numb = int(b[i]) if i < len(b) else 0
    numa -= borrow
    
    if numa < numb:
        borrow = 1
        numa += 10
    else:
        borrow = 0
    num = numa - numb
    ans.append(str(num))

# index = 0
# ans = ans[::-1]
# for i in range(len(ans)):
#     index = i
#     if int(ans[i]) > 0:
#         break
    
ansStr = ''.join(ans[::-1]).lstrip('0')
if not ansStr:
    ansStr = '0'
    
if flag == 1:
    ansStr = '-' + ansStr
print (ansStr)