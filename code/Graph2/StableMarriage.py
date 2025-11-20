# a[i][j]: 첫 번째 그룹의 i번 원소가 두 번째 그룹의 a[i][j]번 원소를 j번째로 선호함
# b[i][j]: 두 번째 그룹의 i번 원소가 첫 번째 그룹의 j번 원소를 b[i][j]번째로 선호함
cnt = [-1]*N
A = [-1]*N
B = [-1]*N
for _ in range(N):
	for i in range(N):
		if A[i] >= 0: continue # 첫 번째 그룹의 i번 원소가 매칭된 경우
		while 1:
			cnt[i] += 1
			w = a[i][cnt[i]] # i번 원소가 다음으로 매칭을 시도할 두 번째 그룹의 원소
			if B[w] < 0: # w번 원소가 아직 매칭되지 않은 경우
				A[i] = w; B[w] = i; break 
			if b[w][i] < b[w][B[w]]: # w번 원소가 현재 매칭된 원소보다 i번 원소를 더 선호하는 경우
				A[i] = w; A[B[w]] = -1; B[w] = i; break 

for i in A: print(i+1)