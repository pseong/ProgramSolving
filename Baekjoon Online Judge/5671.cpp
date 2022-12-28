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

void solve(int n, int m) {
    int ans = 0;
    for (int i=n; i<=m; i++) {
        string s = to_string(i);
        vector<int> chk(10);
        bool ok = true;
        for (int i=0; i<(int)s.size(); i++) {
            if (chk[s[i] - '0']) ok = false;
            else chk[s[i] - '0'] = 1;
        }
        if (ok) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
}