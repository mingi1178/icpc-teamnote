const int SIZE = 1<<17;
vector<int> tree[SIZE*2];
int arr[SIZE];

void init(int node, int S, int E){
    if(S==E){
        tree[node].push_back(arr[S]);
        return;
    }
    int mid = (S+E)/2;
    init(node*2, S, mid);
    init(node*2+1, mid+1, E);
    vector<int> &c = tree[node], &l = tree[node*2], &r = tree[node*2+1];
    c.resize(l.size()+r.size());
    for(int j=0, p=0, q=0; j<c.size(); j++){
        if(q==r.size() || (p<l.size() && l[p]<r[q])) c[j] = l[p++];
        else c[j] = r[q++];
    }
}

// [L, R] 구간에서 k보다 큰 원소의 개수 반환
int query(int L, int R, int k, int node, int S, int E){
    if(R<S || E<L) return 0;
    if(L<=S && E<=R) return tree[node].end()-upper_bound(tree[node].begin(), tree[node].end(), k);
    int mid = (S+E)/2;
    return query(L, R, k, node*2, S, mid)+query(L, R, k, node*2+1, mid+1, E);
}
