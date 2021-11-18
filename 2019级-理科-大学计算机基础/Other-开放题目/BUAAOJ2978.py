str1=input()
fish=str1.split()
F=float(input())
for i in range(0,len(fish)):
    if(int(fish[i])<F/2.0): F=F+int(fish[i])
    elif(int(fish[i])<F): F=F+int(fish[i])/2.0
print("%.1f"%F)

