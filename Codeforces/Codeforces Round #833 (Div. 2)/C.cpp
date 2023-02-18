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
    vector<ll> v(n + 1), pref(n + 1);
    vector<int> idx;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
        if (v[i] == 0) idx.push_back(i);
    }
    idx.push_back(n + 1);
    int s = 1;
    int ans = 0;
    bool flag = false;
    for (int x : idx) {
        if (s == x) {
            flag = true;
            continue;
        }
        if (flag) {
            map<ll, ll> mp;
            for (int i=s; i<x; i++) mp[pref[i]]++;
            ll mx = 0;
            for (auto [x, c] : mp) {
                if (mx < c) mx = c;
            }
            ans += mx;
        }
        else {
            flag = true;
            for (int i=s; i<x; i++) if (pref[i] == 0) ans++;
        }
        s = x;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}