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

const int mod = 998244353;

void solve(int CASE) {
    ll n, k;
    cin >> n >> k;
    ll K = k;
    vector<ll> v(n+1);
    vector<ll> tmp(n+1), tmp2(n+1);
    tmp[0] = 1;
    for (int lo=k; lo<=n; lo+=k) {
        for (int i=lo; i<=n; i++) {
            v[i] += tmp[i-k];
            tmp[i] += tmp[i-k];
            tmp2[i] += tmp[i-k];
            v[i] %= mod;
            tmp[i] %= mod;
            tmp2[i] %= mod;
        }
        for (int i=0; i<=n; i++) {
            tmp[i] = tmp2[i];
            tmp2[i] = 0;
        }
        k++;
    }
    for (int i=1; i<=n; i++) {
        cout << v[i] % mod << ' ';
    }
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}