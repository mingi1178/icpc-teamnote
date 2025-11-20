def find(n):
    if uf[n] < 0: return n
    uf[n] = find(uf[n])
    return uf[n]

def union(a, b):
    a = find(a)
    b = find(b)
    if a == b: return
    if uf[a] > uf[b]: a,b = b,a  # smaller to larger
    uf[a] += uf[b]
    uf[b] = a

uf = [-1]*n