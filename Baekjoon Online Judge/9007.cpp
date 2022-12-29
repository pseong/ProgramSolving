#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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

void solve(int CASE) {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> v(4, vector<int>(n));
    for (int i=0; i<4; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> l, r;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            l.push_back(v[0][i] + v[1][j]);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            r.push_back(v[2][i] + v[3][j]);
        }
    }
    sort(r.begin(), r.end());
    int ans = 1e9;
    for (int i=0; i<(int)l.size(); i++) {
        auto it = lower_bound(r.begin(), r.end(), k - l[i]);
        if (it != r.end()) {
            if (abs(k - l[i] - *it) < abs(k - ans)) ans = l[i] + *it;
            else if (abs(k - l[i] - *it) == abs(k - ans)) ans = min(ans, l[i] + *it);
        }
        if (it != r.begin()) {
            it = prev(it);
            if (abs(k - l[i] - *it) < abs(k - ans)) ans = l[i] + *it;
            else if (abs(k - l[i] - *it) == abs(k - ans)) ans = min(ans, l[i] + *it);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}