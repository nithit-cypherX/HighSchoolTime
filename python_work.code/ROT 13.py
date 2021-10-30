import string
print('Select 2 options'+ '\n' + ' - 1 encrypt with ROT 13 ' + '\n'+ ' - 2 decrypt with ROT 13' + '\n')
choose =int(input('Choose option: '))
if choose == 2:
    x = 13
elif choose == 1:
    x = -13

text = input('Enter text: ')
sume = ""

for i in text :
    if i in  string.ascii_uppercase:
        z =string.ascii_uppercase.find(i)+x
        sume +=(str.upper(string.ascii_letters)[z])
    elif i in string.ascii_lowercase: 
        z =string.ascii_lowercase.find(i)+x
        sume +=(str.lower(string.ascii_letters)[z])
    else:
        sume += i
if choose ==1: 
    print('Ciphertext is '+'"'+sume+'"')   
elif choose == 2:
    print('Plaintext is '+'"'+sume+'"')            
