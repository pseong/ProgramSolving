#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const ll inf = 500000000000000LL;

int r, n, score[210];
vector<int> v[210];
ll a[210], b[210], c[210];

void dfs(int x) {

    a[x] = b[x] = score[x];
    c[x] = -inf;

    for (int y : v[x]) {
        dfs(y);

        b[x] = max(b[x], b[y]);
        if (a[y] > 0) {
            a[x] += a[y];
            c[x] = max(c[x], c[y]);
        }
        else {
            c[x] = max(c[x], b[y]);
        }
    }
    b[x] = max(b[x], a[x]);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int p;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> score[i] >> p;
        if (p == -1) r = i;
        else v[p].push_back(i);
    }

    dfs(r);
    
    ll ans = -inf;
    for (int i=1; i<=n; i++) {
        ans = max(ans, a[i] + c[i]);
        
        vector<ll> v2;
        for (int j : v[i]) v2.push_back(b[j]);

		sort(v2.begin(), v2.end());
		reverse(v2.begin(), v2.end());

        if (v2.size() >= 2) ans = max(ans, v2[0] + v2[1]);
    }

    cout << ans << '\n';
}