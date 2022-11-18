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
    
    multiset<pi> ms[101];
    map<int, pi> mp;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p, l, g;
        cin >> p >> l >> g;
        mp.insert({p, {l, g}});
        ms[g].insert({l, p});
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int p, l, g;
            cin >> p >> l >> g;
            mp.insert({p, {l, g}});
            ms[g].insert({l, p});
        }
        if (s == "recommend") {
            int g, x;
            cin >> g >> x;
            if (x == 1) {
                cout << ms[g].rbegin()->second << '\n';
            }
            if (x == -1) {
                cout << ms[g].begin()->second << '\n';
            }
        }
        if (s == "recommend2") {
            int x;
            cin >> x;
            if (x == 1) {
                pi ans{-1, -1};
                for (int i=1; i<=100; i++) {
                    if (ms[i].size()) {
                        pi at = *ms[i].rbegin();
                        if (at.first > ans.first) {
                            ans = at;
                        }
                        else if (at.first == ans.first) {
                            ans.second = max(ans.second, at.second);
                        }
                    }
                }
                cout << ans.second << '\n';
            }
            if (x == -1) {
                pi ans{1000, 1000};
                for (int i=1; i<=100; i++) {
                    if (ms[i].size()) {
                        pi at = *ms[i].begin();
                        if (at.first < ans.first) {
                            ans = at;
                        }
                        else if (at.first == ans.first) {
                            ans.second = min(ans.second, at.second);
                        }
                    }
                }
                cout << ans.second << '\n';
            }
        }
        if (s == "recommend3") {
            int x, l;
            cin >> x >> l;
            if (x == 1) {
                pi ans{1000, 1000};
                for (int i=1; i<=100; i++) {
                    if (ms[i].size()) {
                        auto it = ms[i].lower_bound({l, 0});
                        if (it == ms[i].end()) continue;
                        pi at = *it;
                        if (at.first < ans.first) {
                            ans = at;
                        }
                        else if (at.first == ans.first) {
                            ans.second = min(ans.second, at.second);
                        }
                    }
                }
                if (ans.first == 1000) cout << -1 << '\n';
                else cout << ans.second << '\n';
            }
            if (x == -1) {
                pi ans{0, 0};
                for (int i=1; i<=100; i++) {
                    if (ms[i].size()) {
                        auto it = ms[i].lower_bound({l, 0});
                        if (it == ms[i].begin()) continue;
                        pi at = *(--it);
                        if (at.first > ans.first) {
                            ans = at;
                        }
                        else if (at.first == ans.first) {
                            ans.second = max(ans.second, at.second);
                        }
                    }
                }
                if (ans.first == 0) cout << -1 << '\n';
                else cout << ans.second << '\n';
            }
        }
        if (s == "solved") {
            int p;
            cin >> p;
            ms[mp[p].second].erase({mp[p].first, p});
            mp.erase(p);
        }
    }
}