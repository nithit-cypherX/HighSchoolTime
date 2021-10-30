n = int(input('Enter number: '))
if n < 0:
    print('Cannot get {}!'.format(n))
else:
    fac = 1
    if n > 1:
        for i in range(1,n+1):
            fac *= i     
    print('{}! = {}'.format(n,fac))        


