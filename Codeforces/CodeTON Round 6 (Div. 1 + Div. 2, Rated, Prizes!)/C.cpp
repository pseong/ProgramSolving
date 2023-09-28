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

const int inf = 1e9;

void solve(int CASE) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1), l(k + 1), r(k + 1), chk(k + 1);
    for (int i=1; i<=n; i++) cin >> v[i], chk[v[i]] = 1;
    for (int i=1, cur=1; i<=n; i++) while (cur <= v[i]) l[cur] = i, cur++;
    for (int i=n, cur=1; i>=1; i--) while (cur <= v[i]) r[cur] = i, cur++;
    for (int i=1; i<=k; i++) {
        if (!chk[i]) cout << 0 << ' ';
        else cout << 2 * (r[i] - l[i] + 1) << ' ';
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