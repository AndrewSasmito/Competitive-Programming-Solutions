n1 = int(input())
n2 = int(input())
ans = 2
while (n1 >= n2):
    n3 = n1 - n2
    n1 = n2
    n2 = n3
    ans += 1
print(ans)
