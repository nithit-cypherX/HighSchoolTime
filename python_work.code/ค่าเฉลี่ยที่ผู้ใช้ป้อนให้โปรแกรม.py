x = int(input('Enter number: '))
l = []
e = []
l.append(x)
e.append(x)
if x >= 0:
    while x>0:
        x = int(input('Enter number: '))
        l.append(x)
        e.append(x)

    else : 
        val = l.pop()
        y = min(l)
        v = max(e)
        print("Minimum number is {}".format(y))
        print("Maximum number is {}".format(v))    
        



'''
else    :
    z = max(x)
    n.append(z)
    print("Minimum number is {}".format(z))    
'''    