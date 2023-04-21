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
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    for (int i=0; i<n; i++) {
        if (s[i] != s[0]) ok = false;
    }
    if (ok) {
        cout << 0 << '\n';
        return;
    }
    int ans = 1e9;
    for (char c='a'; c<='z'; c++) {
        int res = 0;
        int cnt = 0;
        for (int i=0; i<=n; i++) {
            if (i == n || s[i] == c) {
                res = max(res, cnt);
                cnt = 0;
            }
            else cnt++;
        }
        int go = 0;
        while (res >= (1<<(go+1))) go++;
        ans = min(ans, go + 1);
    }
    cout << ans << '\n';
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