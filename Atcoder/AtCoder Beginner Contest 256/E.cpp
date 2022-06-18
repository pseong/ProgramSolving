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

int in[202020], chk[202020], ans;

void solve() {
    int n; cin >> n;
    vector<int> v(n+1), c(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }

    for (int i=1; i<=n; i++) {
        in[v[i]]++;
    }

    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (in[i] == 0) q.push(i);
    }

    while (q.size()) {
        int x = q.front();
        q.pop();
        chk[x] = 1;
        int y = v[x];
        in[y]--;
        if (in[y] == 0) {
            q.push(y);
        }
    }

    for (int i=1; i<=n; i++) {
        if (!chk[i]) {
            int go = i;
            int mn = -1;
            while (!chk[go]) {
                chk[go] = 1;
                if (mn == -1) mn = c[go];
                else mn = min(mn, c[go]);
                go = v[go];
            }
            ans += mn;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}