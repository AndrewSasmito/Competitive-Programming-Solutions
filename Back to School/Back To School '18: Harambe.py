s1 = input()
s2 = input()
n = int(input())
score = 0

for i in range(len(s1)):
    if (s1[i] != s2[i]):
        score += 1
        
    if (s1[i] == ' ' and s2[i].isalpha()):
        score = 10000000
    
    if (s2[i] == ' ' and s1[i].isalpha()):
        score = 10000000
        

print ("Plagiarized" if score <= n else "No plagiarism")
