#This took way too long to solve (adhoc skills need to be improved!)

#You need problem solving in order to be a good competitive programmer
n = int(input())
cur = 1
ans = 2
if (n <= 2):
    print(1)
else:
    for i in range(2, n):
        
        if (i % 2 == 0):
            cur += 2
        
        ans += cur
        
        if (ans >= n):
            print(i)
            break
