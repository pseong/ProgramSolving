#include <bits/stdc++.h>
#define int long long
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

ll f(ll x) {
    set<ll> st;
    ll ans = x;
    while (st.find(x) == st.end()) {
        st.insert(x);
        ans = min(ans, x);
        ll x2 = 0;
        while (x) {
            x2 = x2*10 + (x%10);
            x /= 10;
        }
        x = x2;
    }
    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll k1 = k;
    int ans = 0;
    set<ll> st;
    if (st.find(k) == st.end() && k <= n && f(k) == k) {
        ans++;
        st.insert(k);
    }

    ll tmp = k;
    ll k2 = 0;
    while (tmp) {
        k2 = k2*10 + (tmp%10);
        tmp /= 10;
    }
    if (st.find(k2) == st.end() && k2 <= n && f(k2) == k) {
        ans++;
        st.insert(k2);
    }
    k1 *= 10;
    k2 *= 10;
    while (k1 <= n || k2 <= n) {
        if (st.find(k1) == st.end() && k1 <= n && f(k) == k) {
            st.insert(k1);
            ans++;
        }
        if (st.find(k2) == st.end() && k2 <= n && f(k2) == k) {
            st.insert(k2);
            ans++;
        }
        k1 *= 10;
        k2 *= 10;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}