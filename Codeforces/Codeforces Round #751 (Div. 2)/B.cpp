#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
 
int an[2020][2010];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    int T;
    cin >> T;
    while(T--) {
        int n, q;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> an[0][i];
        }
        for(int k=1; k<=n; k++) {
            int cnt[2020]{0};
            for(int i=1; i<=n; i++) {
                cnt[an[k-1][i]]++;
            }
            for(int i=1; i<=n; i++) {
                an[k][i] = cnt[an[k-1][i]];
            }
        }
        cin >> q;
        for(int i=0; i<q; i++) {
            int a, k;
            cin >> a >> k;
            k = min(k, n);
            cout << an[k][a] << '\n';
        }
    }
}