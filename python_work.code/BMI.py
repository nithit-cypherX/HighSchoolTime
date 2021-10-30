g = input('Enter Gender (M/W): ')
if g.find('M')== -1 and g.find('W')== -1:
    print(g,'is not M or W')
    exit()
y = int(input('Enter current year: ')) 
b =int(input("Enter your birth year: ")) 
e =  float(input('Enter your weight (kg): '))
h = float(input('Enter your height (cm): '))
print('- '*6,'\n'+'Your age =',y-b)
bmi =((e/h**2)*10**4)
print('Your BMI =',round(bmi,3))
if g == 'M':
    bmr = (66.5+(13.75*e)+(5.003*h)-(6.755*(y-b)))
elif g =='W':
    bmr = (655.1+(9.563*e)+(1.850*h)-(4.676*(y-b)))
print('Your BMR =','{:.3f}'.format(bmr))

