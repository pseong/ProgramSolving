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
    vector<tuple<int, char, int, char>> ans;
    map<pair<char, char>, vector<int>> mp;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        map<char, int> m;
        vector<char> give, need;
        for (char c : s) m[c]++;
        for (char c : {'w', 'i', 'n'}) {
            if (m[c] == 0) need.push_back(c);
            else {
                for (int i=1; i<(int)m[c]; i++) {
                    give.push_back(c);
                }
            }
        }
        for (int j=0; j<(int)need.size(); j++) {
            char x = give[j];
            char y = need[j];
            if (mp[{y, x}].size()) {
                ans.push_back({i, x, mp[{y, x}].back(), y});
                mp[{y, x}].pop_back();
            }
            else mp[{x, y}].push_back(i);
        }
    }
    char ch[] {'w', 'i', 'n'};
    if (mp[{ch[0], ch[1]}].empty()) swap(ch[0], ch[1]);
    while (mp[{ch[0], ch[1]}].size()) {
        int x = mp[{ch[0], ch[1]}].back();
        int y = mp[{ch[1], ch[2]}].back();
        int z = mp[{ch[2], ch[0]}].back();
        ans.push_back({x, ch[0], y, ch[1]});
        ans.push_back({y, ch[0], z, ch[2]});
        mp[{ch[0], ch[1]}].pop_back();
        mp[{ch[1], ch[2]}].pop_back();
        mp[{ch[2], ch[0]}].pop_back();
    }
    cout << ans.size() << '\n';
    for (auto [a, b, c, d] : ans) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
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