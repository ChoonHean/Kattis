ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
n = ii()
n += 1
f = [1, 1]
for i in range(2, 2 * n + 1): f.append(f[-1] * i)
print(f[2 * n] // f[n] // f[n] // (n + 1))
