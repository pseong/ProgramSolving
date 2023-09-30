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
    int n;
    cin >> n;
    vector<ll> v(n);
    ll x = 0;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            v[i] |= (1LL << c);
        }
        x |= v[i];
    }
    int ans = 0;
    for (int i=1; i<=50; i++) {
        if (x >> i & 1) {
            ll y = 0;
            for (int j=0; j<n; j++) {
                if (~v[j] >> i & 1) {
                    y |= v[j];
                }
            }
            ans = max(ans, __builtin_popcountll(y));
        }
    }
    cout << ans << '\n';
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