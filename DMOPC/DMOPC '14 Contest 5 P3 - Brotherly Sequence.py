def main():
    n = int(input())
    v = list(map(int, input().split()))
    
    ans = 0
    cnt = 1
    
    for i in range(1, n):
        if (abs(v[i] - v[i-1]) <= 2):
            cnt += 1
        else:
            ans = max(ans, cnt)
            cnt = 1
    ans = max(ans, cnt)

    print(ans)



main()
