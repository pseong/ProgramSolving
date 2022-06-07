#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using ti=tuple<int, int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n), v2(n);
        for (int i=0; i<n; i++) cin >> v[i];
        for (int i=0; i<n; i++) cin >> v2[i];

        vector<ti> an(n);
        for (int i=0; i<n; i++) {
            an[i] = {v[i], v2[i], i};
        }
        sort(an.begin(), an.end());
        int now = 0;
        int ans[n]{ 0 };
        for (int i=0; i<n; i++) {
            int given, end, idx;
            tie(given, end, idx) = an[i];
            if (now < given) now = given;
            int start = max(now, given);
            ans[idx] = end - start;
            now = end;
        }

        for (int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}