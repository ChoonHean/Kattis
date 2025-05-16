ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())

from fractions import *

n, m = mii()
a = lmii()
b = lmii()


def f(a):
    res = Fraction(a[-1])
    for i in range(len(a) - 2, -1, -1): res = a[i] + 1 / res
    return res


x, y = f(a), f(b)


def g(frac):
    res = []
    while frac.denominator != 1:
        res.append(frac.numerator // frac.denominator)
        frac = 1 / (frac - res[-1])
    res.append(frac.numerator)
    return res


print(*g(x + y))
print(*g(x - y))
print(*g(x * y))
print(*g(x / y))
