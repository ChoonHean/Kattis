ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
n = ii()
n //= 4
print(4 + 2 * n * (n - 1))
