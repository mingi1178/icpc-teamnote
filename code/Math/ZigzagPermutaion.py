MAX = 101
E = [[0]*MAX for _ in range(MAX)] #Entringer Number
E[0][0] = 1
for n in range(1, MAX):
    for k in range(1, n+1): E[n][k] = E[n][k-1]+E[n-1][n-k]
# 2*E[N][N]: 1부터 N까지 자연수를 나열한 수열이 지그재그 순열이 되는 경우의 수