# 길이만 구하기
from bisect import bisect_left
N = int(input())
A = [*map(int,input().split())]
L = []
for num in A:
    i = bisect_left(L, num)
    if i < len(L): L[i] = num
    else: L.append(num)
print(len(L))

# 수열 구하기
N = int(input())
A = [*map(int,input().split())]
lis = []
idx = 0
index = [0]*N
for i in range(N):
    k = bisect_left(lis, A[i])
    if k < idx:
        lis[k] = A[i]
        index[i] = k
    else:
        lis.append(A[i])
        index[i] = idx
        idx += 1
print(idx)  # 길이

ans = [0]*idx
idx -= 1
for i in range(N-1, -1, -1):
    if idx == index[i]:
        ans[idx] = A[i]
        idx -= 1
print(*ans)  # 수열