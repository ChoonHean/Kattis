import sys

for l in sys.stdin.readlines():
    n, k = map(int, l.split())
    f, a = [], []
    for i in range(1, n + 1): f.append(k % i);k //= i;a.append(i)
    print(*[a.pop(i) for i in f[::-1]])
