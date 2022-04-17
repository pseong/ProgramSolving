#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
ll an[202020];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll sum = 0;
        for (int i=1; i<=n; i++) {
            cin >> an[i];
            sum += an[i];
        }
        ll cost = sum * b;
        ll ans = cost;
        for (int i=1; i<=n; i++) {
            cost -= ((n-i) * (an[i] - an[i-1])) * b;
            cost += (an[i] - an[i-1]) * a;
            ans = min(ans, cost);
        }
        cout << ans << '\n';
    }
}