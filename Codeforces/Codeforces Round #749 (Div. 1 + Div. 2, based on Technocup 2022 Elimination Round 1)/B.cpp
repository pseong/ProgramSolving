#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int node[100010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            node[b] = 1;
        }
        memset(node, 0, sizeof(node));
        int ans=0;
        for(int i=1; i<=n; i++) {
            if(node[i]==0) {
                ans = i;
                break;
            }
        }
        for(int i=1; i<=n; i++) {
            if(i==ans) continue;
            cout << ans << ' ' << i << '\n';
        }
    }
}