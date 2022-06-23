#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

string mp[500];
int pref[500][500];

int get(int li, int lj, int ri, int rj) {
    return pref[ri][rj] - pref[li-1][rj] - pref[ri][lj-1] + pref[li-1][lj-1];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> mp[i];
        mp[i].insert(mp[i].begin(), '0');
    }
    mp[0] = string(m+1, '0');
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mp[i][j] - '0';
        }
    }

    vector<int> f(m+1, 0);
    int ans = n*m;
    for (int i=1; i<=n-4; i++) {
        for (int j=i+4; j<=n; j++) {
            f.assign(m+1, 0);
            for (int k=4; k<=m; k++) {
                f[k] = get(i+1, 1, j-1, k-1) - get(i, 1, i, k-1) - get(j, 1, j, k-1) - get(i+1, k, j-1, k) + 2*k + j - i - 3;
            }
            for (int k=m-1; k>=4; k--) {
                f[k] = min(f[k], f[k+1]);
            }
            for (int k=1; k<=m-3; k++) {
                ans = min(ans, f[k+3] - get(i+1, 1, j-1, k) - (k - get(i, 1, i, k)) - (k - get(j, 1, j, k)) + (j-i-1 - get(i+1, k, j-1, k)));
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}