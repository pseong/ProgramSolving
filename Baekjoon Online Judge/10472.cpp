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
    vector<string> w(3);
    for (int i=0; i<3; i++) {
        cin >> w[i];
    }
    int ans = 1e9;
    for (int k=0; k<(1<<9); k++) {
        vector<string> t{"...", "...", "..."};
        int cnt = 0;
        for (int i=0; i<9; i++) {
            if (k & (1<<i)) {
                cnt++;
                int x = i / 3;
                int y = i % 3;
                int dx[] {0, -1, 1, 0, 0};
                int dy[] {0, 0, 0, -1, 1};
                for (int d=0; d<5; d++) {
                    int a = x + dx[d];
                    int b = y + dy[d];
                    if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
                    t[a][b] ^= '.' ^ '*';
                }
            }
        }
        if (t == w) ans = min(ans, cnt);
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