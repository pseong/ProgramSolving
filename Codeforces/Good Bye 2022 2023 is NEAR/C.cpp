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
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i=1; i<n; i++) {
        if (v[i] == v[i-1]) {
            no();
            return;
        }
    }
    map<ll, set<ll>> mp;
    for (ll i=0; i<n; i++) {
        for (ll j=i+1; j<n; j++) {
            ll d = abs(v[i] - v[j]);
            if (d == 0) continue;
            for (ll k=2; k<=110; k++) {
                if (d % k == 0) {
                    mp[k].insert(v[i] % k);
                    mp[k].insert(v[j] % k);
                }
            }
        }
    }
    for (auto [a, st] : mp) {
        ll prev = -2;
        ll res = 0;
        ll now = 1;
        for (ll i : st) {
            if (i == prev + 1) {
                now++;
                res = max(res, now);
            }
            else {
                now = 1;
            }
            prev = i;
        }
        if (res >= a) {
            no();
            return;
        }
    }
    yes();
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