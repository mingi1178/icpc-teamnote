#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
int sqrtN;

struct Query{
    int idx, s, e;
    bool operator < (Query &x){
        if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
        return e < x.e;
    }
};

int main(){
    fastio;
    int N, M; cin >> N >> M;
    sqrtN = sqrt(N);

    int A[N+1];
    for(int i=1; i<=N; i++) cin >> A[i];

    Query query[M];
    for(int i=0; i<M; i++){
        int s, e; cin >> s >> e;
        query[i] = Query({i, s, e});
    }
    sort(query, query+M);

    // 구간 [s, e]의 합을 구하는 예제
    ll sum = 0, ans[M];
    int s = query[0].s, e = query[0].e;
    for(int i=s; i<=e; i++) sum += A[i];
    ans[query[0].idx] = sum;

    for(int i=1; i<M; i++){
        while(s < query[i].s) sum -= A[s++];
        while(s > query[i].s) sum += A[--s];
        while(e < query[i].e) sum += A[++e];
        while(e > query[i].e) sum -= A[e--];
        ans[query[i].idx] = sum;
    }
    for(int i=0; i<M; i++) cout << ans[i] << '\n';
}