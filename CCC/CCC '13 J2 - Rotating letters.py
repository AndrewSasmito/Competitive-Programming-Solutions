def main():
    n = input()
    
    #  I, O, S, H, Z, X, and N.
    
    for i in range(len(n)):
        if (n[i] != 'I' and n[i] != 'O' and n[i] != 'S' and n[i] != 'H' and n[i] != 'Z' and n[i] != 'X' and n[i] != 'N'):
            print("NO")
            return
    else:
        print("YES")
        
main()
