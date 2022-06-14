p = int(input())
n = int(input())
r = int(input())

cur = n
day = 0
while (n <= p):
    day += 1
    
    cur = cur * r
    n += cur
print(day)
