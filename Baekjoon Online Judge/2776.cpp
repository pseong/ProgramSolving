#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int v[1000010];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v, v+n);
        int m;
        cin >> m;
        for(int i=0; i<m; i++) {
            int a;
            cin >> a;
            int idx=lower_bound(v, v+n, a)-v;
            if(idx==n||v[idx]!=a) cout << 0;
            else cout << 1;
            cout << '\n';
        }
    }
}