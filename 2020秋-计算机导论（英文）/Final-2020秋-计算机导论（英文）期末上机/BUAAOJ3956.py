n = int(input())
for i in range (0, n):
    a, b = map(float, input().split())
    s = input()
    if s[0] == '+':
        print(round(a + b, 3))
    if s[0] == '-':
        print(round(a - b, 3))
    if s[0] == '*':
        print(round(a * b, 3))
    if s[0] == '/':
        print(round(a / b, 3))
