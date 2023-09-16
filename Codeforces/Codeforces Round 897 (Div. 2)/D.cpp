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
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1), s(n + 1), d(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    int t = 0;
    bool ok = true;
    for (int i=1; i<=n; i++) {
        if (d[i]) continue;
        if (k == 1 && v[i] != i) ok = false;
        int x = i;
        int cyc;
        while (1) {
            d[x] = ++t;
            s[x] = i;
            if (d[v[x]]) {
                if (s[v[x]] == s[x]) cyc = d[x] - d[v[x]] + 1;
                else cyc = -1;
                break;
            }
            x = v[x];
        }
        if (cyc != -1 && cyc != k) ok = false;
    }
    if (ok) yes();
    else no();
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