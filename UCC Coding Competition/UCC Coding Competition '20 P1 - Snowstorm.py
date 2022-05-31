n = int(input())
s1 = input()
s2 = input()
ans = 0
for i in range (n):
    if (s1[i] == '0' and s2[i] == '0'):
        ans += 1
print(ans)
