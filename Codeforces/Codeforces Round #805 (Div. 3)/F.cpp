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

void solve() {
    ll n;
    cin >> n;
    multiset<ll> to, from;
    int a;
    for (int i=0; i<n; i++) {
        cin >> a;
        while (a%2 == 0) a /= 2;
        to.insert(a);
    }
    for (int i=0; i<n; i++) {
        cin >> a;
        while (a%2 == 0) a /= 2;
        from.insert(a);
    }
    for (ll x : from) {
        ll go = x;
        while (go >= 1) {
            while (go%2 == 0) go /= 2;
            auto it = to.find(go);
            if (it != to.end()) {
                to.erase(it);
                goto g;
            }
            go /= 2;
        }
        no();
        return;
        g:
        continue;
    }
    yes();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}