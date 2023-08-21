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
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> v(m + 2);
    for (int i=1; i<=m; i++) cin >> v[i];
    v[0] = 1 - d;
    v[m + 1] = n + 1;

    int sum = 0;
    for (int i=1; i<=m+1; i++) {
        sum += (v[i] - v[i-1] - 1) / d;
    }

    vector<int> ans(2, 1e9);
    for (int i=1; i<=m; i++) {
        int res = sum;
        res -= (v[i] - v[i-1] - 1) / d;
        res -= (v[i+1] - v[i] - 1) / d;
        res += (v[i+1] - v[i-1] - 1) / d;
        res += m - 1;
        if (ans[0] == res) ans[1]++;
        else if (ans[0] > res) ans[0] = res, ans[1] = 1;
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
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