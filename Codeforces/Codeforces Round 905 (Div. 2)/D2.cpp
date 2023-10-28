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
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1), b(n);
    for (int i=0; i<n-1; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    srt(a);
    srt(b);
    vector<int> chk(n);
    int cur = 0;
    for (int i=0; i<n-1; i++) {
        while (cur < n && a[i] >= b[cur]) cur++;
        if (cur == n) break;
        chk[cur] = 1;
        cur++;
    }
    ll k = 0, last = 1;
    for (int i=0; i<n; i++) if (!chk[i]) k++, last = b[i];
    if (m < last) cout << (k - 1) * m << '\n';
    else cout << (last - 1) * (k - 1) + (m - last + 1) * k << '\n';
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