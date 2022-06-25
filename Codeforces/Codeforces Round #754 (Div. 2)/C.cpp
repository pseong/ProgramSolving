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

const int inf = 1000000000;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (s[i] == 'a') v.push_back(i);
    }
    int ans = inf;
    for (int i=1; i<(int) v.size(); i++) {
        if (v[i] - v[i-1] == 1) ans = 2LL;
        else if (v[i] - v[i-1] == 2) ans = min(ans, 3LL);
        else if (v[i] - v[i-1] == 3) {
            if (s[v[i-1]+1] != s[v[i]-1]) ans = min(ans, 4LL);
        }
    }
    for (int i=0; i<n-6; i++) {
        string str = s.substr(i, 7);
        if (str == "abbacca" || str == "accabba") {
            ans = min(ans, 7LL);
        }
    }
    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}