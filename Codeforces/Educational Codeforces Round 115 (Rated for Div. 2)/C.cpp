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

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        sum += v[i];
        mp[v[i]]++;
    }
    if (2*sum % n == 0) {
        int to = 2*sum / n;
        int ans = 0;
        for (int i=0; i<n; i++) {
            int a1 = v[i];
            int a2 = to - v[i];
            if (mp.find(a2) != mp.end()) ans += mp[a2];
            if (a1 == a2) ans--;
        }
        cout << ans / 2 << '\n';
    }
    else cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}