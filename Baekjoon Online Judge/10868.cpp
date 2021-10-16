#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
ll an[N+1];
ll st[N*4];
int n, m;

ll init(int node, int s, int e) {
    if(s==e) return st[node] = an[s];
    int m=s+e>>1;
    return st[node] = min(init(node*2, s, m), init(node*2+1, m+1, e));
}

ll query(int node, int l, int r, int s, int e) {
    if(e<l||s>r) return 1000000000;
    if(s<=l&&e>=r) return st[node];
    int m=r+l>>1;
    return min(query(node*2, l, m, s, e), query(node*2+1, m+1, r, s , e));
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    init(1, 1, n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << '\n';
    }
}