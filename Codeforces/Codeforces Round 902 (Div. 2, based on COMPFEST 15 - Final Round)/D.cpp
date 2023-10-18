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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    const ll mod = 998244353;
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        for (int j=i+i; j<=n; j+=i) {
            if (v[i] < v[j]) v[i] = v[j];
        }
    }
    sort(v.begin() + 1, v.end());
    ll ans = 0, p = 1;
    for (int i=1; i<=n; i++) {
        ans += p * v[i];
        p *= 2;
        ans %= mod;
        p %= mod;
    }
    cout << ans << '\n';
}