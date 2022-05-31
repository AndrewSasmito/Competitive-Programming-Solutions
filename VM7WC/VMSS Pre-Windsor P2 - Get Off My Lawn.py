import math
dis = -1
ansx = 0
ansy = 0
for i in range (int(input())):
    x = list(map(int, input().split()))
    
    if (math.sqrt((x[0]*x[0]) + (x[1]*x[1])) > dis):
        dis = math.sqrt((x[0]*x[0]) + (x[1]*x[1]))
        ansx = x[0]
        ansy = x[1]
print(ansx, ansy)
