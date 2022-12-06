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

int cnt[202020][2];
vector<int> adj[202020];

ll go(int x, int p) {
    ll c = 0;
    for (int y : adj[x]) {
        if (y == p) continue;
        c += go(y, x);
    }
    return max(c + cnt[x][0] - cnt[x][1], 0LL);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'S') cnt[i][0] = a;
        else cnt[i][1] = a;
        adj[b].push_back(i);
    }
    cout << go(1, 0) << '\n';
}