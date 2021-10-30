x = int(input('Enter number #1: '))
y = 2
l = []
e = []
if x >= 0:
    for i in range(0,19):    
        x = int(input('Enter number #{}: '.format(y)))
        y = 1+y
        l.append(x)
        e.append(x)
        