ans = 0
for _ in range(int(input())):
    m = input()
    
    if (m == "Poblano"):
        ans += 1500
    elif (m == "Mirasol"):
        ans += 6000
    elif (m == "Serrano"):
        ans += 15500
    elif(m == "Cayenne"):
        ans += 40000
    elif (m == "Thai"):
        ans += 75000
    else:
        ans += 125000
print(ans)
