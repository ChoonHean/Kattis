t = int(input())
from math import gcd

for _ in range(t):
    arr = list(map(int, input().split()))
    n = arr.pop(0)
    arr.sort()
    g = 0
    for i in range(1, n):
        g = gcd(g, arr[i] - arr[i - 1])
    print(f"Case #{_ + 1}: {(g - (arr[-1] % g)) % g}")
