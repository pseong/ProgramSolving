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
    string a, b;
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        if (a[0] ^ b[0] ^ a[i] ^ b[i]) {
            no();
            return;
        }
    }
    vector<pi> ans;
    for (int i=0; i<n; i++) {
        if (a[i] == '1') ans.push_back({i + 1, i + 1});
    }
    if (a[0] ^ b[0] ^ (ans.size() % 2 )) {
        ans.push_back({1, n});
        ans.push_back({1, 1});
        ans.push_back({2, n});
    }
    yes();
    cout << ans.size() << '\n';
    for (auto [s, e] : ans) {
        cout << s << ' ' << e << '\n';
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