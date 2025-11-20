#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
// 13만-> 1 << 17 (131072), 26만-> 1 << 18 (262144)
// 52만-> 1 << 19 (524288), 100만-> 1 << 20 (1048576)
const int SIZE = 1<<20;
ll tree[SIZE*2];
ll arr[SIZE];

ll merge(ll a, ll b){
    return a+b;
}

// k번째 수를 반환
int getkth(int k, int node, int S, int E){
    if(S==E) return S;
    int mid = (S+E)/2;
    if(tree[node*2]>=k) return getkth(k, node*2, S, mid);
    else return getkth(k-tree[node*2], node*2+1, mid+1, E);
}

// X번째 수를 V로 지정
void update(int X, ll V, int node, int S, int E){
    if(S==E){
        tree[node] = V;
        return;
    }
    int mid = (S+E)/2;
    if(X<=mid) update(X, V, node*2, S, mid);
    else update(X, V, node*2+1, mid+1, E);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}

// [L, R] 구간 쿼리
ll query(int L, int R, int node, int S, int E){
    if(R<S || E<L) return 0;  // 항등원
    if(L<=S && E<=R) return tree[node];
    int mid = (S+E)/2;
    return merge(query(L, R, node*2, S, mid), query(L, R, node*2+1, mid+1, E));
}

// S-based indexing으로 초기화
ll init(int node, int S, int E){
    if(S==E) return tree[node] = arr[S];
    int mid = (S+E)/2;
    return tree[node] = merge(init(node*2, S, mid), init(node*2+1, mid+1, E));
}

int main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);
    for(int i=0; i<m+k; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1) update(b, c, 1, 1, n);
        else cout << query(b, c, 1, 1, n) << '\n';
    }
}