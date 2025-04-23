ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(mii())
while True:
    n, m = mii()
    if not n and not m: break
    res = 0
    carry = 0
    while n or m:
        carry = 1 if n % 10 + m % 10 + carry >= 10 else 0
        n //= 10
        m //= 10
        res += carry
    if res == 0:
        print("No carry operation.")
    elif res == 1:
        print("1 carry operation.")
    else:
        print(res, "carry operations.")
