#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=2000000;
int st[N*4];
int n;

int query(int node, int s, int e, int k) {
    st[node]--;
    if(s==e) return s;
    int m=s+e>>1;
    if(st[node*2]>=k) return query(node*2, s, m, k);
    else return query(node*2+1, m+1, e, k-st[node*2]);
}

int update(int node, int s, int e, int idx) {
    if (idx<s||idx>e) return st[node];
    if(s==e) return ++st[node];
    int m=s+e>>1;
    return st[node] = update(2*node, s, m, idx)+update(node*2+1, m+1, e, idx);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int s, x;
        cin >> s >> x;
        if(s==1) {
            update(1, 1, N, x);
        }
        else {
            cout << query(1, 1, N, x) << '\n';
        }
    }
}