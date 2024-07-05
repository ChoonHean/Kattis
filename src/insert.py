from math import comb
from functools import cache


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.size = 1


@cache
def s(n, k):
    if k == 0: return 0
    if n == k: return 1
    return s(n - 1, k) + s(n - 1, k - 1)


def f(node):
    if node.left is None:
        if node.right is None: return 1
        return f(node.right)
    if node.right is None:
        return f(node.left)
    l = node.left.size
    r = node.right.size
    res = 0
    if l < r: l, r = r, l
    for i in range(1, r + 1):
        res += comb(l + 1, i) * s(r, i)
    res = res * f(node.left) * f(node.right)
    return res


while True:
    n = int(input())
    if n == 0: break
    arr = tuple(map(int, input().split()))
    root = Node(arr[0])
    for i in arr[1:]:
        curr = root
        while True:
            curr.size += 1
            if i < curr.val:
                if curr.left is None:
                    curr.left = Node(i)
                    break
                curr = curr.left
            else:
                if curr.right == None:
                    curr.right = Node(i)
                    break
                curr = curr.right
    print(f(root))
