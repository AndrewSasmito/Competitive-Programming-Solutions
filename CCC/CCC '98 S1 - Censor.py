n = int(input())

for i in range (n):
    a = list(map(str, input().split()))

    for j in range (len(a)):
        if (len(a[j]) == 4):
            print('****', end = " ")
        else:
            print(a[j], end = " ")

    print('\n')
