ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
from datetime import datetime, timedelta
from heapq import *

t = ii()
for _ in range(t):
    n, c = mii()
    arr = []
    for i in range(n):
        cur = list(input().split())
        arr.append((datetime.strptime(cur[1] + ' ' + cur[2], "%Y-%m-%d %H:%M"),
                    datetime.strptime(cur[3] + ' ' + cur[4], "%Y-%m-%d %H:%M")))
    arr.sort()
    res = 1
    pq = [datetime(2000, 1, 1)]
    for s, e in arr:
        if s >= pq[0]:
            cur = heappop(pq)
        else:
            res += 1
        heappush(pq, e + timedelta(minutes=c))
    print(res)
