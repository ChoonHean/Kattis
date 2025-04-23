ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
from decimal import Decimal, getcontext

getcontext().prec = 100
a, b, c = map(Decimal, lmii())
print(format(a * b / c, 'f'))
