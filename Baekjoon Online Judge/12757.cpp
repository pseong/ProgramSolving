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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int a, b;
            cin >> a >> b;
            if (mp.count(a) == 0) mp[a] = b;
        }
        else if (what == 2) {
            int a, b;
            cin >> a >> b;
            auto it = mp.lower_bound(a);
            vector<pi> can;
            if (it != mp.end()) {
                auto [key, value] = *it;
                if (abs(a - key) <= k) {
                    can.push_back({key, value});
                }
            }
            if (it != mp.begin()) {
                auto [key, value] = *prev(it);
                if (abs(a - key) <= k) {
                    can.push_back({key, value});
                }
            }
            if (can.size() == 1) mp[can[0].first] = b;
            else if (can.size() == 2) {
                if (abs(can[0].first - a) == abs(can[1].first - a)) continue;
                else if (abs(can[0].first - a) < abs(can[1].first - a)) mp[can[0].first] = b;
                else mp[can[1].first] = b;
            }
        }
        else if (what == 3) {
            int a;
            cin >> a;
            auto it = mp.lower_bound(a);
            vector<pi> can;
            if (it != mp.end()) {
                auto [key, value] = *it;
                if (abs(a - key) <= k) {
                    can.push_back({key, value});
                }
            }
            if (it != mp.begin()) {
                auto [key, value] = *prev(it);
                if (abs(a - key) <= k) {
                    can.push_back({key, value});
                }
            }
            if (can.empty()) cout << -1 << '\n';
            else if (can.size() == 1) cout << can[0].second << '\n';
            else if (can.size() == 2) {
                if (abs(can[0].first - a) == abs(can[1].first - a)) cout << '?' << '\n';
                else if (abs(can[0].first - a) < abs(can[1].first - a)) cout << can[0].second << '\n';
                else cout << can[1].second << '\n'; 
            }
        }
    }
}