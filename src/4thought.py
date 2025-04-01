a,b=['4'],[]
for i in range(3):
    for s in a:
        b.append(s+' + 4')
        b.append(s+' - 4')
        b.append(s+' * 4')
        b.append(s+' // 4')
    a,b=b,a
mp=dict()
for s in a:
    i=eval(s)
    mp[eval(s)]=s.replace('//','/')+' = '+str(i)
n=int(input())
for _ in range(n):
    i=int(input())
    print(mp.get(i,'no solution'))
