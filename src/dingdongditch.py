n,q=map(int,input().split())
a=sorted(map(int,input().split()))
b=[a[0]]
for i in range(1,n):
    b.append(b[i-1]+a[i])
c=map(int,input().split())
for i in c:
    print(b[i-1])