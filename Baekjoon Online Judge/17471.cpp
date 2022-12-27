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

vector<int> adj[10];
int n;

bool f(vector<int> c, int z) {
    int s = 0;
    for (int i=0; i<n; i++) {
        if (c[i] == z) s = i;
    }
    queue<int> q;
    q.push(s);
    c[s] = z^1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (c[y] != z) continue;
            c[y] = z^1;
            q.push(y);
        }
    }
    bool ok = true;
    for (int i=0; i<n; i++) {
        if (c[i] == z) ok = false;
    }
    return ok;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int a;
            cin >> a;
            a--;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
    }
    int ans = 1e9;
    for (int k=1; k<(1<<n)-1; k++) {
        vector<int> chk(n);
        for (int i=0; i<n; i++) {
            if (k & (1<<i)) chk[i] = 1;
        }
        if (f(chk, 0) && f(chk, 1)) {
            vector<int> p(2);
            for (int i=0; i<n; i++) {
                p[chk[i]] += v[i];
            }
            ans = min(ans, abs(p[0] - p[1]));
        }
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}