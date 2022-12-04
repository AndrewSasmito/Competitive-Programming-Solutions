n = list(map(int, input().split()))
n.sort()
x = input()
ans = "ABC"
for i in range(3):
    for j in range(3):
        if (ans[j] == x[i]):
            print(n[j], end=" ")
            break
