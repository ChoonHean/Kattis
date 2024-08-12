n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
res,fac,mod=0,1,1000000007
for i in range(k-1,n):
    res=(res+fac*arr[i])%mod
    fac=fac*(i+1)//(i+2-k)
print(int(res))
