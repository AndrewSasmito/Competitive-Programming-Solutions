n = int(input())

ans = 0;
for i in range (1, n + 1):
    if (i * i <= n):
        ans = i
    else:
        break

print("The largest square has side length", ans, end=".")
