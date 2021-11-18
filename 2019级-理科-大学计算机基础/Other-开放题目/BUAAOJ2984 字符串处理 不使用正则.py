import math
n = int(input())
i = 0
code = []
while i < n:
    obj = str(input())
    code.append(obj)
    i = i + 1
i = 0
while i < n:
    code[i]=code[i].expandtabs(tabsize=4)
    code[i]=code[i].replace("#","# ",1)
    code[i]=code[i].replace("#  ","# ",1)
    pbj = code[i]
    cb = len(code[i])
    cd = len(pbj.lstrip())
    cc = cb - cd
    code[i]=code[i].lstrip()
    pq = (math.ceil(cc/4))*4
    code[i] = code[i].rjust((pq+cd))
    print(code[i])
    i = i+1
