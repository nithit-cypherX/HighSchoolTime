from math import sqrt
print('*'*30+'\n'+'*'*9+'About Circle'+'*'*9+'\n'+'*'*30)
z = float(input('Input radius: '))
pi = 3.141592653589793
area = (pi*(z*z))
cir = (2*pi*z)
print('Radius is',z)
print('Circumference is', round(cir,4))
print('Area is', round(area,2) )
y = float(input('Enter y for finding x : '))
x = '{:.4f}'.format(sqrt((z**2)-(y**2)))
print('y is {0:.4f}'.format(y))
print('x is '+ ('-'+x) + " and " + x )
print('******************************')