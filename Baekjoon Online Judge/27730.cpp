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

const int MX = 101010;
vector<pll> adj1[MX], adj2[MX];
ll ch1[MX], ch2[MX];
ll a1[MX], a2[MX];
ll c1[MX], c2[MX];
ll u1[MX], u2[MX];
ll n, m;

void dfs1(int x, int p) {
    c1[x] = 1;
    for (auto [y, c] : adj1[x]) {
        if (y == p) continue;
        dfs1(y, x);
        c1[x] += c1[y];
        ch1[x] += ch1[y] + c * c1[y];
    }
}

void dfs2(int x, int p) {
    c2[x] = 1;
    for (auto [y, c] : adj2[x]) {
        if (y == p) continue;
        dfs2(y, x);
        c2[x] += c2[y];
        ch2[x] += ch2[y] + c * c2[y];
    }
}

void d1(int x, int p) {
    for (auto [y, c] : adj1[x]) {
        if (y == p) continue;
        u1[y] = u1[x] + (ch1[x] - (ch1[y] + c * c1[y])) + c * (n - c1[y]); // n 주의m 으로 바꿔야 함
        d1(y, x);
    }
}

void d2(int x, int p) {
    for (auto [y, c] : adj2[x]) {
        if (y == p) continue;
        u2[y] = u2[x] + (ch2[x] - (ch2[y] + c * c2[y])) + c * (m - c2[y]); // n 주의m 으로 바꿔야 함
        d2(y, x);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj1[a].push_back({b, c});
        adj1[b].push_back({a, c});
    }
    cin >> m;
    for (int i=0; i<m-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj2[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
    dfs1(1, 0);
    dfs2(1, 0);
    d1(1, 0);
    d2(1, 0);
    for (int i=1; i<=n; i++) {
        a1[i] = ch1[i] + u1[i];
    }
    for (int i=1; i<=m; i++) {
        a2[i] = ch2[i] + u2[i];
    }
    int x = min_element(a1+1, a1+n+1) - a1;
    int y = min_element(a2+1, a2+m+1) - a2;
    cout << x << ' ' << y << '\n';
    cout << a1[x] * m + a2[y] * n + m * n;
}

// mx 바꿔야 함