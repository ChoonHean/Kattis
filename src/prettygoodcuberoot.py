import sys
from decimal import Decimal, getcontext
getcontext().prec=1000
for l in sys.stdin.readlines():
    i=Decimal(int(l))
    print(round(i**(Decimal(1)/Decimal(3))))