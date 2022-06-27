#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans(n+1);
    ans[1] = a;
    ans[n/2+1] = b;
    vector<int> chk(n+1);
    chk[a] = 1;
    chk[b] = 1;
    int go = n;
    for (int i=2; i<=n/2; i++) {
        while (chk[go]) go--;
        if (go <= 0 || go < a) {
            cout << -1 << '\n';
            return;
        }
        chk[go] = 1;
        ans[i] = go;
    }
    go = 1;
    for (int i=n/2+2; i<=n; i++) {
        while (chk[go]) go++;
        if (go > n || go > b) {
            cout << -1 << '\n';
            return;
        }
        chk[go] = 1;
        ans[i] = go;
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}