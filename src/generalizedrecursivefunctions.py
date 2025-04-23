ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
t = ii()
from functools import lru_cache

for _ in range(t):
    arr = lmii()


    @lru_cache(maxsize=None)
    def f(x, y):
        if x <= 0 or y <= 0: return d
        res = c
        for i in range(0, n, 2): res += f(x - arr[i], y - arr[i + 1])
        return res


    d = arr.pop()
    c = arr.pop()
    n = len(arr)
    nums = lmii()
    for i in range(0, len(nums), 2): print(f(nums[i], nums[i + 1]))
    print()
