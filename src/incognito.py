ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())

from sys import stdin
from math import comb

t = ii()
for _ in range(t):
    n = ii()
    d = {}
    for i in range(n):
        s, t = input().split()
        d[t] = d.get(t, 0) + 1
    res = 1
    for i in d.values(): res *= i + 1
    print(res - 1)
