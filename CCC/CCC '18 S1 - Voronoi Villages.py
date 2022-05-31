n = int(input())

a = []

for i in range (n):
    hold = int(input())
    a.append(hold)

a.sort()
ans = 1e9
for i in range (1, n-1):
    ans = min((a[i+1] - a[i-1])/2, ans)

print(ans)
