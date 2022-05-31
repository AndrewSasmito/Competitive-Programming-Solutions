number = int(input())

speed = []
value = []

for i in range (number):
    DistanceTime = list(map(int, input().split()))
    value.append(DistanceTime)

value = sorted(value)

for i in range (len(value)-1):
    speed.append(abs(value[i][1] - value[i+1][1])/abs(value[i][0]- value[i+1][0]))

speed = sorted(speed)

print (speed[-1])
