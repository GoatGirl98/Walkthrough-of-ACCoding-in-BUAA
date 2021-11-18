n = input()
m = list()
s=""
m.insert(0,n[0].lower())
j=1
#for i in range(1, len(n)):print(n[i])
for i in range(1, len(n)):
    if n[i]<='Z':
       m.insert(j,'_')
       j+=1
       m.insert(j,n[i].lower())
       j+=1
    else:
        m.insert(j,n[i])
        j+=1
for i in range(0, len(m)):s+=m[i]
print(s)
