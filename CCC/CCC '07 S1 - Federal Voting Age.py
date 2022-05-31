ans = 0

n = int(input())

for i in range (n):
    v = list(map(int, input().split()))
    
    if (v[0] > 1989):
        print("No")
    elif (v[0] < 1989):
        print("Yes")
    else:
        if (v[1] > 2):
            print("No")
        elif (v[1] < 2):
            print("Yes")
        else:
            if (v[2] <= 27):
                print("Yes")
            elif (v[2] > 27):
                print("No")
