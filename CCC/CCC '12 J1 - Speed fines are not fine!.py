j = int(input())
i = int(input())

# 20 30 else

if (i <= j):
    print("Congratulations, you are within the speed limit!")
elif (i - j <= 20):
    print("You are speeding and your fine is $100.")
elif (i - j <= 30):
    print("You are speeding and your fine is $270.")
else:
    print("You are speeding and your fine is $500.")
