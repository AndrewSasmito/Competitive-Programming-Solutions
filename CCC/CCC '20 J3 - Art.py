x1 = 101
x2 = -1
y1 = 101
y2 = -1

for i in range(int(input())):
    n = list(map(int, input().split(',')))
    
    x1 = min(x1, n[0])
    x2 = max(x2, n[0])
    y1 = min(y1, n[1])
    y2 = max(y2, n[1])

print(x1 - 1, end="")
print(',', end="")
print(y1 - 1)

print(x2 + 1, end="")
print(',', end="")
print(y2 + 1)
