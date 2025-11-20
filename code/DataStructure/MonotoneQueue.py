from collections import deque
import sys
input = sys.stdin.readline
N, L = map(int, input().split())
a = [*map(int, input().split())]
chain = deque()
ans = [0]*N
for r in range(N):
    while chain and a[chain[-1]]>a[r]: chain.pop()
    chain.append(r)
    if r>=L and chain[0]==r-L: chain.popleft()
    ans[r] = a[chain[0]]
print(*ans)