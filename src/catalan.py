n=int(input())
N=10001
f=[1]
for i in range(1,N):f.append(f[-1]*i)
for _ in range(n):
    x=int(input())
    print(f[2*x]//f[x+1]//f[x])