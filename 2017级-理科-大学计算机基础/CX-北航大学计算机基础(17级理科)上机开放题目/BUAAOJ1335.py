map = [[0] for _ in range(210)]
map[1] = 1
map[2] = 2
for i in range(3, 210):
    map[i] = map[i-1]+map[i-2]

n = int(input())
print(map[n])
