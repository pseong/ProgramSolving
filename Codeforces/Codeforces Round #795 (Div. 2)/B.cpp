#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, vector<int>> mp;
        vector<int> v(n+1);
        for (int i=1; i<=n; i++) {
            cin >> v[i];
            mp[v[i]].push_back(i);
        }

        vector<int> ans(n+1);
        bool ok = true;
        for (auto at : mp) {
            if (at.second.size() == 1) {
                ok = false;
                break;
            }
            vector<int>& as = at.second;
            int sz = as.size();
            as.push_back(as.front());
            for (int i=0; i<sz; i++) {
                ans[as[i]] = as[i+1];
            }
        }
        if (!ok) cout << -1 << '\n';
        else {
            for (int i=1; i<=n; i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
}