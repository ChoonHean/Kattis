ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())

from fractions import *

n, q = mii()
a = []
for i in range(n):
    x, y = mii()
    a.append((Fraction(y - x, 100), x))
for _ in range(q):
    u, v, cur = mii()
    cur = Fraction(cur)
    cur -= a[u - 1][1]
    cur /= a[u - 1][0]
    cur *= a[v - 1][0]
    cur += a[v - 1][1]
    print(f'{cur.numerator}/{cur.denominator}')
