def main():
    m = int(input())
    d = int(input())

    if (m < 2):
        print("Before\n")
    elif (2 < m):
        print("After\n")
    elif (2 == m):
        if (d < 18):
            print("Before\n")
        elif (18 < d):
            print("After\n")
        elif (18 == d):
            print("Special\n")



main()
