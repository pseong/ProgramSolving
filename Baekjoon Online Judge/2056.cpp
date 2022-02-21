#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, a[10010], ind[10010], t[10010];
vector<int> v[10010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> ind[i];
        for (int j=0; j<ind[i]; j++) {
            int c;
            cin >> c;
            v[c].push_back(i);
        }
    }

    queue<int> que;
    for (int i=1; i<=n; i++) {
        if (ind[i] == 0) {
            t[i] = a[i];
            que.push(i);
        }
    }

    int ans = 0;
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        ans = max(ans, t[x]);
        for (int y : v[x]) {
            ind[y]--;
            t[y] = max(t[y], t[x]+a[y]);
            if (ind[y] == 0) {
                que.push(y);
            }
        }
    }

    cout << ans;
}