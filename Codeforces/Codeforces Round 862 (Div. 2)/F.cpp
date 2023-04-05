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

const ll mod = 1e9 + 7;
ll ans = 0;

ll powll(ll n, ll k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    ll x = powll(n, k/2);
    if (k%2 == 0) return x * x % mod;
    else return x * x % mod * n % mod;
}

vector<int> f(vector<int> v) {
    int n = v.size();
    sort(v.begin(), v.end());
    ll mn = v.front();
    for (int i=0; i<n; i++) v[i] -= mn;
    ans += mn * powll(2, n - 1) % mod;
    ans %= mod;
    priority_queue<ti, vector<ti>, greater<ti>> q;
    vector<int> ret;
    for (int i=0; i<n-1; i++) {
        q.push({v[i] + v[i+1], i, i + 1});
    }
    for (int k=0; k<n-1; k++) {
        auto [x, i, j] = q.top();
        q.pop();
        ret.push_back(x);
        if (j < n - 1) {
            q.push({v[i] + v[j+1], i, j + 1});
        }
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<=n-1; i++) {
        v = f(v);
    }
    cout << (ans + v[0]) % mod << '\n';
}