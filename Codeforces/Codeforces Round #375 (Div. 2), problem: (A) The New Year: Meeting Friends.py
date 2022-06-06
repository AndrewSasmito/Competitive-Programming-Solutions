x1, x2, x3 = input().split()
 
x1 = int(x1)
x2 = int(x2)
x3 = int(x3)
 
count = max(x1, x2, x3) - min(x1, x2, x3)
print(count)
