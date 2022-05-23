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
        vector<pi> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i].first;
            v[i].second = i;
        }
        vector<pi> v2 = v;
        sort(v2.begin(), v2.end());
        int ans = -1;
        for (int i=0; i<n; i++) {
            if (v[i].second != v2[i].second) {
                if (ans == -1) ans = v[i].first;
                else ans &= v[i].first;
            }
        }
        cout << ans << '\n';
    }
}