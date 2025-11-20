#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 
const ll INF = 1e9; 
struct Node {  
    ll LMax; // 왼쪽에서 시작한 부분합 중 최댓값 
    ll RMax; // 오른쪽에서 시작한 부분합 중 최댓값 
    ll Max;  // 그냥 최댓값 
    ll Sum;  // 그냥 합 
    Node() { 
        LMax = RMax = Max = Sum = -INF; 
    } 
    void setVal(ll x) { 
        LMax = RMax = Max = Sum = x; 
    } 
}; 
int N; 
ll arr[100001]; 
Node SegTree[400001]; 

Node merge(Node lNode, Node rNode) { 
    Node ret; 
    ret.LMax = max(lNode.LMax, lNode.Sum + rNode.LMax); 
    ret.RMax = max(rNode.RMax, lNode.RMax + rNode.Sum); 
    ret.Max = max({lNode.Max, rNode.Max, lNode.RMax + rNode.LMax}); 
    ret.Sum = lNode.Sum + rNode.Sum; 
    return ret; 
} 
void init(int idx, int st, int ed) { 
    if (st == ed) { 
        SegTree[idx].setVal(arr[st]); 
        return; 
    } 
    int mid = (st+ed)/2; 
    init(2*idx, st, mid); 
    init(2*idx+1, mid+1, ed); 
    SegTree[idx] = merge(SegTree[2*idx], SegTree[2*idx+1]); 
} 
Node query(int idx, int nodeSt, int nodeEd, int reqSt, int reqEd) { 
    if(reqEd<nodeSt || nodeEd < reqSt) return Node(); 
    else if (reqSt <= nodeSt && nodeEd <= reqEd) return SegTree[idx]; 
    else { 
        int nodeMid = (nodeSt + nodeEd)/2; 
        Node left = query(2*idx,nodeSt,nodeMid,reqSt,reqEd); 
        Node right = query(2*idx+1,nodeMid+1,nodeEd,reqSt,reqEd); 
        return merge(left,right); 
    } 
} 
int main() { 
    cin.tie(0)->sync_with_stdio(0); 
    cin >> N; 
    for (int i=0;i<N;i++) cin >> arr[i]; 
    init(1,0,N-1); 
    int T; cin >> T; 
    while (T--) { 
        int a, b; 
        cin >> a >> b; 
        a--; b--; 
        Node ret = query(1,0,N-1,a,b); 
        cout << ret.Max << '\n'; 
    } 
    return 0; 
} 