"""
题目描述
有形如：ax^3+bx^2+cx+d=0 这样的一个一元三次方程。给出该方程中各项的系数（a,b,c,d 均为实数），
并约定该方程存在三个不同实根（根的范围在 −100 至 100 之间），且根与根之差的绝对值 ≥1。
要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后 2 位。

提示：记方程 f(x)=0，若存在 2 个数 x1​和 x2​，且 x1<x2，f(x1​) × f(x2)<0，则在 (x 1,x 2​) 之间一定有一个根。

输入格式
一行，4 个实数 a,b,c,d。

输出格式
一行，3 个实根，从小到大输出，并精确到小数点后 2 位。
"""

def f(a, b, c, d, x):
    return float(a * x * x * x + b * x * x + c * x + d)

def halfCut(a, b, c, d, l, r):
    mid = -1.0
    while (r - l) > 1e-5:
        mid = (l + r) / 2
        midNum = f(a, b, c, d, mid)
        rNum = f(a, b, c, d, r)
        if midNum * rNum < 0:
            l = mid
        elif midNum == 0:
            return mid
        elif rNum == 0:
            return r
        else:
            r = mid
    return r

a, b, c, d = map(float, input().strip().split())

result = []

for i in range(-100, 100):
    num1 = f(a, b, c, d, i)
    num2 = f(a, b, c, d, i + 1)
    if num1 == 0:
        result.append(i)
    if num1 * num2 < 0:
        ans = halfCut(a, b, c, d, i, i + 1)
        result.append(ans)
        
print(' '.join(f"{x:.2f}" for x in result))