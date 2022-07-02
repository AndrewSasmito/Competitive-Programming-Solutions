n1 = list(map(int, input().split()))
n2 = list(map(int, input().split()))

n = int(input())

diff = abs(n1[0] - n2[0]) + abs(n1[1] - n2[1])

if ((n-diff) % 2 == 0 and (n - diff) >= 0):
    print("Y")
else:
    print("N")
