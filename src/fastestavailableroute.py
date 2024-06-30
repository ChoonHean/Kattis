h, w, s = map(int, input().split())
a = 1
while h: a += input().count('.');h -= 1
print("Your destination will arrive in %d meters" % (a * s))
