n = int(input())
ans = n

for i in range (int(input())):
    ans += n * pow(10, i + 1)
print(ans)
