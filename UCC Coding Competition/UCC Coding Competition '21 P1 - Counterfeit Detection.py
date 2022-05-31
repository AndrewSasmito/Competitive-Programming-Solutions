n = input()
ans = 0
for i in range (len(n)):
    if (n[i] == '4'):
        continue
    if (n[i] == '6'):
        continue
    if (n[i] == '2'):
        if (i == len(n) - 1):
            ans += 1
        elif (n[i+1] != '5'):
            ans += 1
    elif (n[i] == '5'):
        if (i == 0):
            ans += 1
        elif (n[i - 1] != '2'):
            ans += 1
    else:
        ans += 1
print(ans)
