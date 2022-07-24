#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
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
    ll n;
    cin >> n;
    vector<ll> v(n-1);
    map<ll, ll> mp;
    mp[0]++;
    for (ll i=0; i<n-1; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<ll> vec;
    for (auto at : mp) {
        vec.push_back(at.second);
    }
    srtrev(vec);
    ll sz = vec.size();
    ll ans = sz;
    multiset<ll> ms;
    for (ll i=0; i<sz; i++) {
        if (vec[i] - 1 - (sz - i - 1) > 0) ms.insert(vec[i] - 1 - (sz - i - 1));
    }
    ll tm = 0;
    while (ms.size()) {
        tm++;
        while (ms.size() && *ms.begin() <= tm) {
            ms.erase(ms.begin());
        }
        if (ms.empty()) break;
        ll a = *ms.rbegin();
        auto it = ms.lower_bound(a);
        ms.erase(it);
        if (a-1 > tm) ms.insert(a-1);
    }
    cout << ans + tm << '\n';
}
    
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        solve(t);
    }
}