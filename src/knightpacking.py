print('?', *range(n := int(input())))
print('!', int(input()) - (n - 1) * n * n // 2 + 1)
