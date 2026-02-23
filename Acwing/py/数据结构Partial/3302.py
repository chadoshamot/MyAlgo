s = input().strip()
stack1 = []
stack2 = []
def isOp(op):
    return op == '+' or op == '-' or op == '*' or op == '/'

def getNum(op):
    if op == '+':
        return 1
    elif op == '-':
        return 1
    elif op == '*':
        return 2
    elif op == '/':
        return 2
    else:
        return -1
def isSmaller(op1, op2):
    # define whether op1 is smaller than op2
    n1 = getNum(op1)
    n2 = getNum(op2)
    return n1 <= n2

def isNum(op):
    return op <= '9' and op >= '0'

def div(n2, n1):
    if(n2 // n1 < 0):
        num = (-n2) // n1
        num = -num
        return num
    else:
        return n2 // n1

def calc(n1, n2, op):
    # n2 op n1
    if op == '+':
        return n2 + n1
    if op == '-':
        return n2 - n1
    if op == '*':
        return n2 * n1
    if op == '/':
        return div(n2, n1)
    
def evaluate():
    op = stack2[-1]
    stack2.pop()
    n1 = stack1[-1]
    stack1.pop()
    n2 = stack1[-1]
    stack1.pop()
    ret = calc(n1, n2, op)
    stack1.append(ret)

i = 0
while i < len(s):
    op = s[i]
    if isNum(op):
        x = 0
        while i < len(s) and isNum(s[i]):
            x = x * 10 + int(s[i])
            i += 1
        stack1.append(x)
    elif s[i] == '(':
        stack2.append(s[i])
        i += 1
    elif s[i] == ')':
        while stack2[-1] != '(':
            evaluate()
        stack2.pop()
        i += 1
    elif isOp(s[i]):
        while len(stack1) > 1 and len(stack2) > 0 and isSmaller(s[i], stack2[-1]):
            evaluate()
        stack2.append(s[i])
        i += 1

while len(stack2) > 0:
    evaluate()
    
print(stack1[-1])