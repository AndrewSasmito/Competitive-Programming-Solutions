num = int(input())
 
lists = []
 
answer = []
for i in range(num):
    data = input()
    lists.append(data)
copied = lists.copy()
for j in range(num):
    test = list(copied[j])
    maximum = 0
    wrong = len(lists[j])
    for i in range(wrong-2, -1, -1):
        number1 = int(lists[j][i])
        number2 = int(lists[j][i+1])
        number = number1+number2
        if number>=10:
            second = number-10
            test[i] = str(1)
            test[i+1] = str(second)
            break
    else:
        test[1] = str(int(test[0]) + int(test[1]))
        test.pop(0)
    print("".join(test))
    test.clear()
