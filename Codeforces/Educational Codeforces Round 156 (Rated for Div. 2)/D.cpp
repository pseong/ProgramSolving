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

const ll mod = 998244353;

ll powll(ll n, ll r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    ll x = powll(n, r/2);
    if (r%2 == 0) return x * x % mod;
    else return x * x % mod * n % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll ans = 1;
    for (int i=1; i<n; i++) {
        if (s[i] == '?') {
            ans *= i;
            ans %= mod;
        }
    }
    auto prt = [&]() -> void {
        if (s[0] == '?') cout << 0 << '\n';
        else cout << ans << '\n';
    };
    prt();
    for (int i=0; i<m; i++) {
        int x;
        char c;
        cin >> x >> c;
        x--;
        if (s[x] == '<' || s[x] == '>') {
            if (c == '?') {
                if (x != 0) ans *= x;
            }
        }
        else {
            if (c == '<' || c == '>') {
                if (x != 0) ans *= powll(x, mod - 2);
            }
        }
        ans %= mod;
        s[x] = c;
        prt();
    }
}