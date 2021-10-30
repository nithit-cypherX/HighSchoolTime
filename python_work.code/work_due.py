import random

g = int(input('Enter your number:'))
l = []
for i in range(g):
    r_num = random.randint(0,100)
    l.append(r_num)
print(l)
