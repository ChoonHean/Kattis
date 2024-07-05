from itertools import permutations as p

N = 10000001
sieve = [0] * N
primes = []
for i in range(2, N):
    if sieve[i] == 0:
        primes.append(i)
        for j in range(i * i, N, i):
            sieve[j] = 1
t = int(input())
for _ in range(t):
    s = input()
    res = 0
    unique = set((0, 1))
    for i in range(1, len(s) + 1):
        for j in p(s, i):
            curr = int(''.join(j))
            if curr not in unique:
                unique.add(curr)
                if sieve[curr] == 0:
                    res += 1
    print(res)
