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

int q(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int r; cin >> r;
    return r;
}

void add(int x) {
    cout << "+ " << x << endl;
    int r; cin >> r;
}

void solve(int CASE) {
    int n;
    cin >> n;
    int r;
    if (n == 2) {
        cout << "! 1 2 2 1" << endl;
        cin >> r;
        return;
    }
    add(n + 1);
    add(n);
    int up = -1;
    int x = 1;
    for (int i=2; i<=n; i++) {
        r = q(1, i);
        if (r > up) up = r, x = i;
    }
    vector<int> dist(n + 1);
    for (int i=1; i<=n; i++) {
        if (i == x) continue;
        dist[i] = q(i, x);
    }
    vector<pi> v(n + 1);
    for (int i=1; i<=n; i++) {
        v[i].first = dist[i];
        v[i].second = i;
    }
    sort(v.begin() + 1, v.end());
    vector<int> d(n + 1);
    for (int i=1; i<=n; i+=2) {
        d[i] = n - i/2;
    }
    for (int i=2; i<=n; i+=2) {
        d[i] = i/2;
    }
    cout << "! ";
    vector<int> ans(n + 1);
    for (int i=1; i<=n; i++) ans[v[i].second] = d[i];
    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
    for (int i=n; i>=1; i--) ans[v[n-i+1].second] = d[i];
    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << endl;
    cin >> r;
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