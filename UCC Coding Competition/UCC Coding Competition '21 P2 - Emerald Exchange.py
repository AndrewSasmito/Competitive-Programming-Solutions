n = int(input())
h = list(map(int, input().split()))
ans = 0
cur = 0
for i in range (n):
    if (h[i]%2 == 1):
        ans = max(ans, cur)
        cur = 0
    else:
        cur += h[i]

print(max(cur, ans))
