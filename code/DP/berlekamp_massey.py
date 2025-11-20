mod = 1_000_000_007

# x에 3×(가장 짧은 점화식 길이) 이상의 항을 넣어줘야 함. 모듈러는 소수여야 함.
def berlekamp_massey(x):
    ls=[]; cur=[]
    lf=ld=0
    for i in range(len(x)):
        t=0
        for j in range(len(cur)): t=(t+x[i-j-1]*cur[j])%mod
        if(t-x[i])%mod==0: continue
        if len(cur)==0:
            cur.append(0)
            lf=i
            ld=(t-x[i])%mod
            continue
        k=-(x[i]-t)*pow(ld,mod-2,mod)%mod
        c=[k]
        for j in ls: c.append(-j*k%mod)
        if len(c)<len(cur):c+=[0]*(len(cur)-len(c))
        for j in range(len(cur)): c[j]=(c[j]+cur[j])%mod
        if i-lf+len(ls)>=len(cur): ls,lf,ld=cur,i,(t-x[i])%mod
        cur=c
    for i in cur: i=(i%mod+mod)%mod
    return cur

# n번째 항을 반환 (키타마사법)
# rec: 점화식, dp: 초기항
def get_nth(rec, dp, n):
    m=len(rec)
    s=[0]*m; t=[0]*m
    s[0]=1
    if m!=1: t[1]=1
    else: t[0]=rec[0]
    def mul(v, w):
        m=len(v)
        t=[0]*(2*m)
        for j in range(m):
            for k in range(m):
                t[j+k]+=v[j]*w[k]%mod
                if t[j+k]>=mod: t[j+k]-=mod
        for j in range(2*m-1,m-1,-1):
            for k in range(1,m+1):
                t[j-k]+=t[j]*rec[k-1]%mod
                if t[j-k]>=mod: t[j-k]-=mod
        return t[:m]
    while n:
        if n&1:s=mul(s,t)
        t=mul(t,t)
        n>>=1
    ret=0
    for i in range(m): ret+=s[i]*dp[i]%mod
    return ret%mod

# 수열 x의 n번째 항을 반환
def guess_nth_term(x, n):
    if n<len(x): return x[n]
    v=berlekamp_massey(x)
    if len(v)==0: return 0
    return get_nth(v, x, n)