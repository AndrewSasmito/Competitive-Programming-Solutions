
n = int(input())
j = list(map(int, input().split()))
f = 0
for i in range(n):
    if (j[i] == 1):
        f = 1
        break
 
print(-1 if f == 1 else 1)
