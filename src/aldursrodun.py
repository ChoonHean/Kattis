from itertools import permutations
from math import gcd

n = int(input())
for i in permutations(map(int, input().split()), n):
    run = True
    if gcd(i[0], i[1]) == 1: run = False
    if gcd(i[-1], i[-2]) == 1: run = False
    if run:
        for j in range(1, len(i) - 2):
            if gcd(i[j], i[j + 1]) == 1: run = False
            if gcd(i[j], i[j - 1]) == 1: run = False
        if run:
            print(*i)
            break
if not run: print('Neibb')
