v = list(input().split())

if (v[len(v) - 1] == "True"):
    if (len(v) % 2 == 1):
        print("True")
    else:
        print("False")
elif (v[len(v) - 1] == "False"):
    if (len(v) % 2 == 1):
        print("False")
    else:
        print("True")
