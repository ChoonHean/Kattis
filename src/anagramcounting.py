ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())

from sys import stdin
from math import comb

for s in stdin.readlines():
    d = dict()
    s = s.strip()
    for c in s: d[c] = d.get(c, 0) + 1
    res = 1
    n = len(s)
    for i in d.values(): res *= comb(n, i);n -= i
    print(res)
