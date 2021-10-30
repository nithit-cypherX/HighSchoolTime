n = int(input('Enter the number of rows: '))*2
s = input('Enter print symbol: ')
for i in range(n,0,-1):
    print(' '*((n-i)//2) + s*i)


    
