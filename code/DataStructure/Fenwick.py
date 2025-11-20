SIZE = 1<<17
tree = [0]*SIZE

# 1-based
def update(i, diff):
    while i < SIZE:
        tree[i] += diff
        i += i&-i

def getSum(i):
    s = 0
    while i > 0:
        s += tree[i]
        i -= i&-i
    return s