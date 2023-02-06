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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<int> chk(n, -1);
    for (int i=0; i<n; i++) {
        if (chk[i] == -1) {
            int go = i;
            vector<int> g;
            while (go >= 0 && go <= n-1 && chk[go] == -1) {
                g.push_back(go);
                chk[go] = -2;
                go += v[go];
            }
            ll c = 0;
            if (go < 0 || go >= n || chk[go] == 1) c = 1;
            for (int j=0; j<(int)g.size(); j++) {
                chk[g[j]] = c;
            }
        }
    }
    vector<int> cnt(n);
    for (int i=0; i<n; i++) {
        if (i + v[i] >= 0 && i + v[i] < n) cnt[i+v[i]]++;
    }
    queue<int> q;
    for (int i=0; i<n; i++) {
        if (cnt[i] == 0) q.push(i);
    }
    vector<int> t(n);
    while (q.size()) {
        int x = q.front();
        q.pop();
        t[x]++;
        int y = x + v[x];
        if (y < 0 || y >= n) continue;
        t[y] += t[x];
        if (--cnt[y] == 0) q.push(y);
    }
    ll ans = 0;
    ll a = accumulate(chk.begin(), chk.end(), 0);
    vector<int> ck(n);
    ll d = 0;
    ll go = 0;
    while (go >= 0 && go < n && !ck[go]) {
        ans += a - t[go];
        ck[go] = 1;
        d++;
        go = go + v[go];
    }
    if (chk[0]) cout << (n+1)*d + ans + (2*n + 1) * (n - d) << '\n';
    else cout << (n+1)*d + a*d << '\n';
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