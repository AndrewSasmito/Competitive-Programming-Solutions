h = int(input())
t = int(input())

ans = -1

for i in range(1, t):
    n = (i + (2 * pow(i, 2)) + (h * pow(i, 3)) - (6 * pow(i, 4)))
    if (n <= 0):
        ans = i
        break

if (ans == -1):
    print("The balloon does not touch ground in the given time.")
else:
    print("The balloon first touches ground at hour:")
    print(ans)
