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

bool ok(ll x, ll y, multiset<pll> ms) {
    multiset<pll> rms;
    for (auto [x, y] : ms) {
        rms.insert({y, x});
    }
    while (ms.size()) {
        bool k = false;
        auto it = ms.lower_bound({x, -1e18});
        if (it!=ms.end() && it->first == x) {
            y -= it->second;
            rms.erase(rms.find({it->second, it->first}));
            ms.erase(it);
            k = true;
        }

        it = rms.lower_bound({y, -1e18});
        if (it!=rms.end() && it->first == y) {
            x -= it->second;
            ms.erase(ms.find({it->second, it->first}));
            rms.erase(it);
            k = true;
        }
        if (!k) break;
    }
    if (ms.size()) return false;
    else return true;
}

bool comp(pll a, pll b) {
    return a.second < b.second;
}

void solve(int CASE) {
    int n;
    cin >> n;
    vector<pll> v(n);
    ll sum = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].first * v[i].second;
    }
    sort(all(v));
    set<pll> ans;
    multiset<pll> ms(v.begin(), v.end());
    ms.erase(ms.find(v.back()));
    if (sum % v.back().first == 0 && ok(v.back().first, sum / v.back().first - v.back().second, ms)) {
        ans.insert({v.back().first, sum / v.back().first});
    }
    multiset<pll> ms2(v.begin(), v.end());
    sort(all(v), comp);
    ms2.erase(ms2.find(v.back()));
    if (sum % v.back().second == 0 && ok(sum / v.back().second - v.back().first, v.back().second, ms2)) {
        ans.insert({sum / v.back().second, v.back().second});
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
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