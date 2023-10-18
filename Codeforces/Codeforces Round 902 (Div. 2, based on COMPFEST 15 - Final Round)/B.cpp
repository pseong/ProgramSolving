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
    ll n, p;
    cin >> n >> p;
    vector<pll> v(n);
    for (int i=0; i<n; i++) cin >> v[i].second;
    for (int i=0; i<n; i++) cin >> v[i].first;
    srt(v);
    map<ll, ll> mp;
    mp[p] = n;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        auto it = mp.begin();
        ans += it->first;
        it->second--;
        if (it->second == 0) mp.erase(mp.begin());
        mp[v[i].first] += v[i].second;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}