n = int(input())
first = list(map(int, input().split()))
second = list(map(int, input().split()))

counter = 0

for i in range (n):
    counter += (first[i] + first[i+1]) * second[i] / 2
    
print(counter)
