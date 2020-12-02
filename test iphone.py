print("Hello there! I wrote this on an iPhone in Linux!")
name = input("Whats your name? ")
agestr = input("And your age is? ")
age = int(agestr)

print("Hello " + name + "!\nYour age is " + agestr + " right?")

if age > 18:
    print("You can drink beer if you'd want to!")
else:
    print("No beer for you!")
