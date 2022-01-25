import math
r=int(input())
R=int(input())
h=int(input())
v=math.pi*h*(R**2+r**2+r*R)/3
print("%.2f"%v)
