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
    cin >> s;
    int ans = 1;
    vector<char> learn;
    for (int i=0; i<(int) s.size(); i++) {
        bool ok = false;
        for (int j=0; j<(int) learn.size(); j++) {
            if (learn[j] == s[i]) ok = true;
        }
        if (ok) continue;
        if (learn.size() < 3) learn.push_back(s[i]);
        else {
            ans++;
            learn.clear();
            learn.push_back(s[i]);
        }
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