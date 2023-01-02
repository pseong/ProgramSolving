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

ll dist(pi a, pi b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;
    vector<pair<pi, pi>> port(6);
    for (int i=0; i<3; i++) {
        cin >> port[i].first.first >> port[i].first.second >> port[i].second.first >> port[i].second.second;
        port[i+3].first = port[i].second;
        port[i+3].second = port[i].first;
    }
    ll ans = 1e18;
    for (int k=0; k<(1<<6); k++) {
        vector<pair<pi, pi>> use;
        for (int i=0; i<6; i++) {
            if (k & (1<<i)) use.push_back(port[i]);
        }
        sort(use.begin(), use.end());
        do {
            ll now = 0;
            int x = xs;
            int y = ys;
            for (int i=0; i<(int)use.size(); i++) {
                now += dist({x, y}, use[i].first) + 10;
                tie(x, y) = use[i].second;
            }
            now += dist({x, y}, {xe, ye});
            ans = min(ans, now);
        } while (next_permutation(use.begin(), use.end()));
    }
    cout << ans << '\n';
}