from sys import stdin as s
from math import lcm
from functools import reduce
for line in s.readlines():print(reduce(lambda x,y:lcm(x,y),map(int,line.split()),1))