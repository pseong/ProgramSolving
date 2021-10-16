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
ll lz[N*4];
int n, m;

ll init(int node, int s, int e) {
    if(s==e) return st[node] = an[s];
    int m=s+e>>1;
    return st[node] = init(node*2, s, m)+init(node*2+1, m+1, e);
}

void propagation(int node, int l, int r) {
    if(lz[node]) {
        st[node] += (r-l+1)*lz[node];
        if(l!=r) {
            lz[node*2] += lz[node];
            lz[node*2+1] += lz[node];
        }
        lz[node] = 0;
    }
}

ll query(int node, int l, int r, int s, int e) {
    propagation(node, l, r);
    if(e<l||s>r) return 0;
    if(s<=l&&e>=r) return st[node];
    int m=l+r>>1;
    return query(node*2, l, m, s, e)+query(node*2+1, m+1, r, s, e);
}

ll update(int node, int l, int r, int s, int e, int x) {
    propagation(node, l, r);
    if(e<l||r<s) return st[node];
    if(s<=l&&e>=r) {
        lz[node] += x;
        propagation(node, l, r);
        return st[node];
    }
    if(l==r) return st[node] = x;
    int m=l+r>>1;
    return st[node] = update(node*2, l, m, s, e, x)+update(node*2+1, m+1, r, s, e, x);
}


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    init(1, 1, n);

    cin >> m;
    for(int i=0; i<m; i++) {
        int t;
        cin >> t;
        if(t==1) {
            int i, j, k;
            cin >> i >> j >> k;
            update(1, 1, n, i, j, k);
        }
        else if(t==2) {
            int x;
            cin >> x;
            cout << query(1, 1, n, x, x) << '\n';
        }
    }
}