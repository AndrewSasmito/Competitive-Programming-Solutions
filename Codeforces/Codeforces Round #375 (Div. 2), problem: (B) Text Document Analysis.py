n = int(input())
n = n-1
string = list(input())
count = 0
words = 0
j= 0
maximum = 0
 
if n == 0:
    if string[0].isalpha() == True:
        count = 1
    else:
        count = 0
elif n == 1:
    if string[0].isalpha() == True and string[1].isalpha() == True:
        count = 2
    elif string[0].isalpha() == True or string[1].isalpha() == True:
        count = 1
else:
    while j<n:
        
 
        if string[j].isalpha() == True:
            maximum = 1
            while j<n:
                j+=1
                if string[j].isalpha():
                    maximum+=1
                else:
                    if maximum>count:
                        count = maximum
                    if string[j] == "(":
                        j -= 1
                    break
        
 
        elif string[j] == "(":
            while j<n:
                j+=1
                if string[j].isalpha():
                    words+= 1
                    while(string[j].isalpha() == True):
                        j+=1
                if string[j] == ")":
                    break
 
 
 
        j+= 1
 
 
print (max(count, maximum), words)
