s = input()
ans = 1
for i in range(len(s)):
    a1, a2, a3 = 0, 0, 0
    p1, p2 = i - 1, i + 1

    #a1 = odd length
    a1 = 1
    while (True):
        if (p1 < 0 or len(s) <= p2):
            break
        elif (s[p1] != s[p2]):
            break
        p1 -= 1
        p2 += 1
        a1 += 2
    
    p1, p2 = i - 1, i
    while (True):
        if (p1 < 0 or len(s) <= p2):
            break
        elif (s[p1] != s[p2]):
            break
        p1 -= 1
        p2 += 1
        a2 += 2

    p1, p2 = i, i + 1
    while (True):
        if (p1 < 0 or len(s) <= p2):
            break
        elif (s[p1] != s[p2]):
            break
        p1 -= 1
        p2 += 1
        a3 += 2
    
    ans = max(ans, max(a1, max(a2, a3)))


print(ans)
