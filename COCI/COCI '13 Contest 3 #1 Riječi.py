def main():
    a = 1
    b = 0
    
    for i in range(int(input())):
        old = a
        a = b
        b += old
    print(a, b)

main()
