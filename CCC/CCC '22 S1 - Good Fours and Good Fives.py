n = int(input())

ans = 0

if (n%4 == 0):
    ans += 1

for i in range(0, n, 4):
    if ((n-i)%5 == 0):
        ans += 1
        
print(ans)
