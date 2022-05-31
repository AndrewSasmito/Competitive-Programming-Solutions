import math
p = int(input())
b = int(input())
d = int(input())

num = math.floor(p/b)

print(num * d + (p - (b * num)))
