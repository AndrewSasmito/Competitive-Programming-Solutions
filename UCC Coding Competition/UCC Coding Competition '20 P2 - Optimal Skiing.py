ans = 10000000

for i in range (int(input())):
    n = list(map(int, input().split()))
    cur = 0
    for z in range (n[0]):
        cur += n[z + 1]
    ans = min(ans, cur)
print(ans)
