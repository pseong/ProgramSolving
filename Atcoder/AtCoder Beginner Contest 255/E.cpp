#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> s(n-1), x(m);
    for (int i=0; i<n-1; i++) {
        cin >> s[i];
    }
    for (int i=0; i<m; i++) {
        cin >> x[i];
    }
    vector<ll> an(n);
    for (int i=1; i<n; i++) {
        an[i] = s[i-1] - an[i-1];
    }
    map<ll, ll> ecnt, ocnt;
    for (int i=0; i<n; i+=2) {
        ecnt[an[i]]++;
    }
    for (int i=1; i<n; i+=2) {
        ocnt[an[i]]++;
    }

    ll ans = 0;
    for (auto at : ecnt) {
        for (ll y : x) {
            ll diff = y - at.first;
            ll res = 0;
            for (ll z : x) {
                auto it = ecnt.find(z-diff);
                if (it != ecnt.end()) res += it->second;
            }
            for (ll z : x) {
                auto it = ocnt.find(z+diff);
                if (it != ocnt.end()) res += it->second;
            }
            ans = max(ans, res);
        }
    }
    for (auto at : ocnt) {
        for (ll y : x) {
            ll diff = y - at.first;
            ll res = 0;
            for (ll z : x) {
                auto it = ocnt.find(z-diff);
                if (it != ocnt.end()) res += it->second;
            }
            for (ll z : x) {
                auto it = ecnt.find(z+diff);
                if (it != ecnt.end()) res += it->second;
            }
            ans = max(ans, res);
        }
    }
    cout << ans;
}