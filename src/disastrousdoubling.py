ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
n = ii()
a = lmii()
cur = 1
for i in a:
    cur <<= 1
    if i > cur: cur = -1;break;
    cur -= i
print("error" if cur == -1 else cur % (int(1e9 + 7)))
