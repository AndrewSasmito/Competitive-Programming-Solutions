def m1(n):
    for i in range(1, n + 1, 2):
        print(i, end=" ")

def m2(n):
    for i in range(2, n + 1, 2):
        print(i, end=" ")

def main():
    n = int(input())

    if (2 <= n and n < 4):
        print("NO SOLUTION")
        return

    if (n == 4):
        m2(n)
        m1(n)
    else:
        m1(n)
        m2(n)


main()
