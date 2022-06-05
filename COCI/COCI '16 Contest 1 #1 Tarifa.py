cost = int(input())
tot = int(input())
cnt = 0
for i in range(tot):
    n = int(input())
    cnt += n
print ((cost * (tot + 1)) - cnt)
