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
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        v[i].first = l;
        v[i].second = b;
    }
    srt(v);
    vector<pi> w;
    for (int i=0; i<n; i++) {
        if (w.empty() || w.back().second < v[i].first) {
            w.push_back(v[i]);
        }
        if (w.back().second >= v[i].first) {
            w.back().second = max(w.back().second, v[i].second);
        }
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        auto it = upper_bound(w.begin(), w.end(), make_pair(x, (int)1e9));
        if (it != w.begin()) {
            x = max(x, (--it)->second);
        }
        cout << x << ' ';
    }
    cout << '\n';
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