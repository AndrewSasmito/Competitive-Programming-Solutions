import math
for _ in range(int(input())):
    m = list(map(int, input().split()))
    print (math.ceil(m[0] / 2), math.ceil(m[1] / 2))
