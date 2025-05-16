ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
import math

print("JUST RUN!!" if (n := int(input())) >= 12 else sum([math.perm(n, i) for i in range(1, n + 1)]))
