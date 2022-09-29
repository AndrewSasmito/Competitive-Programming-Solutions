for _ in range(int(input())):
    n = int(input())
    m = list(map(int, input().split()))
    ans = 1
    cnt = m[0]
    
    for i in range(1, len(m)):
        if (m[i] >= cnt):
            ans = i + 1
        cnt = abs(cnt - m[i])
    print(ans)
