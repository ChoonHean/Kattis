ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())

while True:
    n = ii()
    if not n: break
    a = []
    i = 0
    n -= 1
    while n:
        if n & 1: a.append(3 ** i)
        i += 1
        n >>= 1
    print(str(a).replace('[', '{ ').replace(']', ' }'))
