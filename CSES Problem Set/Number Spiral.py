for _ in range(int(input())):
    y, x= input().split()
    x = int(x)
    y = int(y)
 
 
    maximum = max(x, y)
    minimum = min(x, y)
 
    if x == 1 and y == 1:
        ans = 1
    elif maximum == y and y%2 == 0:
        ans = y*y - x+1
    elif maximum == y and y%2 != 0:
        ans = (y-1)*(y-1) + x
    
    elif maximum == x and x%2 != 0:
        ans = x*x - y+1 
    elif maximum == x and x%2 == 0:
        ans = (x-1)*(x-1) + y
        
 
    print(ans)
