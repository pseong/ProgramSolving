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
    int n;
    cin >> n;
    vector<int> v(n + 1), prev(n + 1), next(n + 1), p(n + 1);
    map<int, vector<int>> mp;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }
    for (auto [x, y] : mp) {
        for (int i=0; i<y.size(); i++) {
            if (i > 0) prev[y[i]] = 1;
            if (i < y.size() - 1) next[y[i]] = 1;
        }
    }
    for (int i=n; i>=1; i--) {
        if (i < n) p[i] = p[i + 1];
        if (!next[i]) p[i]++;
    }
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        if (prev[i] != 0) continue;
        ans += p[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}