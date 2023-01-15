def main():
    s = input()
    t = input()
    
    for i in range(len(t)):
        for j in range(len(s) - len(t) + 1):
            for k in range(len(t)):
                if (t[(i + k) % len(t)] != s[j + k]):
                    break
            else:
                print("yes")
                return
    
    print("no")


main()
