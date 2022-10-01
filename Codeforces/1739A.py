for _ in range(int(input())):
    m = list(map(int, input().split()))
    
    if (m[0] % 2 == 1):
        m[0] += 1
    if (m[1] % 2 == 1):
        m[1] += 1
        
    print (round(m[0] / 2), round(m[1] / 2))
