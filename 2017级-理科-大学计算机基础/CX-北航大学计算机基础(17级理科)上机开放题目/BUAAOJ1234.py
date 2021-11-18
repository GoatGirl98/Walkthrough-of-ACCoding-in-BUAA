info_dict = dict()
n = int(input())

for i in range(0, n):
    a = input()
    b = input()
    info_dict.update({a: b})
m = int(input())
for i in range(0,m):
    s = input()
    if s in info_dict:
        print(info_dict[s])
    else:
        print("Not Found!")
