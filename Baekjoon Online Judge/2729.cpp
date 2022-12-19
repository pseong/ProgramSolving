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
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = max(a.size(), b.size());
    a.resize(n + 1, '0');
    b.resize(n + 1, '0');
    string ans(n + 1, '0');
    int u = 0;
    for (int i=0; i<=n; i++) {
        int x = a[i] - '0' + b[i] - '0' + u;
        if (x == 0) {
            ans[i] = '0';
            u = 0;
        }
        else if (x == 1) {
            ans[i] = '1';
            u = 0;
        }
        else if (x == 2) {
            ans[i] = '0';
            u = 1;
        }
        else if (x == 3) {
            ans[i] = '1';
            u = 1;
        }
    }
    while (ans.size() && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    if (ans.size()) cout << ans << '\n';
    else cout << 0 << '\n';
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