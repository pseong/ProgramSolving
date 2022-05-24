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
        vector<int> an(n);
        vector<int> bn(n);
        for (int i=0; i<n; i++) cin >> an[i];
        for (int i=0; i<n; i++) cin >> bn[i];
        vector<pi> ans;
        for (int i=0; i<n; i++) {
            for (int j=1; j<n; j++) {
                if (an[j-1] > an[j] || (an[j-1] == an[j] && bn[j-1] > bn[j])) {
                    ans.push_back({j-1, j});
                    swap(an[j-1], an[j]);
                    swap(bn[j-1], bn[j]);
                }
            }
        }
        if (is_sorted(bn.begin(), bn.end())) {
            cout << ans.size() << '\n';
            for (pi p : ans) {
                cout << p.first+1 << ' ' << p.second+1 << '\n';
            }
        }
        else {
            cout << -1 << '\n';
        }
    }
}