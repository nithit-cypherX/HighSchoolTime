n = int(input('Enter number: '))
base2 = ""
it = n
while it > 0:
   frac = int(it% 2)
   base2 = str(frac)+ base2
   it = (it-frac)/ 2
print('{} is {} in base 2.'.format(n,base2)) 
