def solve():
    r, s, m, d, n = map(int, input().split())
    brands = tuple(map(int, input().split()))
    si, mi, di = [set() for i in range(s)], [set() for i in range(m)], [set() for i in range(d)]
    for i in range(s):
        arr = tuple(map(int, input().split()))
        for j in range(1, arr[0] + 1):
            si[i].add(arr[j] - 1)
    for i in range(m):
        arr = tuple(map(int, input().split()))
        for j in range(1, arr[0] + 1):
            mi[i].add(arr[j] - 1)
    for i in range(d):
        arr = tuple(map(int, input().split()))
        for j in range(1, arr[0] + 1):
            di[i].add(arr[j] - 1)
    bad = set()
    for i in range(n):
        x, y = map(int, input().split())
        if x > y: x, y = y, x
        bad.add((x - 1, y - 1))
    res = 0
    for i in range(s):
        for j in range(m):
            if (i, s + j) in bad: continue
            for k in range(d):
                if (i, s + m + k) in bad or (s + j, s + m + k) in bad: continue
                cur = set()
                for l in si[i]: cur.add(l)
                for l in mi[j]: cur.add(l)
                for l in di[k]: cur.add(l)
                add = 1
                for l in cur: add *= brands[l]
                res += add
                if res > 1e18:
                    print('too many')
                    return
    print(res)


solve()
