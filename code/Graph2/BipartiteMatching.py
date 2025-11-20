def dfs(a):
	visited[a]=True
	for b in adj[a]:
		if B[b]==-1: B[b]=a; return True
	for b in adj[a]:
		if not(visited[B[b]]) and dfs(B[b]): B[b]=a; return True
	return False

match=0
B=[-1]*M
for i in range(N):
	visited=[0]*N
	if dfs(i): match+=1
print(match)