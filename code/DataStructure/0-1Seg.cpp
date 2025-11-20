const int SIZE = 1<<16;
int tree[SIZE*2];
int len[SIZE*2];

void update(int L, int R, int V, int node, int S, int E){
    if(R<S || E<L) return;
    if(L<=S && E<=R) tree[node] += V;
    else{
        int mid = (S+E)/2;
        update(L, R, V, node*2, S, mid);
        update(L, R, V, node*2+1, mid+1, E);
    }
    if(tree[node]>0) len[node] = E-S+1;
    else if(S==E) len[node] = 0;
    else len[node] = len[node*2]+len[node*2+1];
}

int query(){return len[1];}