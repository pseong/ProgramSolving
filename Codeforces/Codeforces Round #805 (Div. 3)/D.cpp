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

void solve() {
    string s;
    ll p;
    cin >> s >> p;
    vector<ll> chk(s.size(), 1);
    vector<pll> chars;
    ll x = 0;
    for (int i=0; i<(int) s.size(); i++) {
        chars.push_back({s[i], i});
        x += s[i] - 'a' + 1;
    }
    srtrev(chars);
    for (int i=0; i<(int) s.size(); i++) {
        if (x <= p) break;
        chk[chars[i].second] = 0;
        x -= chars[i].first - 'a' + 1;
    }

    string ans;
    for (int i=0; i<(int) s.size(); i++) {
        if (chk[i]) ans.push_back(s[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}