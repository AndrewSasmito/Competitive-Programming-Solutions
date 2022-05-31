n = int(input())
s1 = input()
s2 = input()
ans = 0

for i in range(n):
    if (s1[i] == 'C' and s2[i] == 'C'):
        ans += 1
print(ans)
