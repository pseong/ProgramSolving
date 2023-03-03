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
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> h(n + m + 1);
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        h[v[i]].push_back(0);
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        h[v[a - 1]].push_back(i + 1);
        h[b].push_back(i + 1);
        v[a-1] = b;
    }
    for (int i=1; i<=n+m; i++) {
        if (h[i].size() % 2) h[i].push_back(m+1);
    }
    ll ans = 0;
    for (int i=1; i<=n+m; i++) {
        ll cnt = 0;
        for (int j=0; j<(int)h[i].size(); j+=2) {
            cnt += h[i][j+1] - h[i][j];
        }
        cnt = m + 1 - cnt;
        ans += m*(m+1)/2 - (cnt-1)*cnt/2;
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