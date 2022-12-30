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

int ans, v[30][30], chk[30];

void go(int idx, int now) {
    if (idx == 11) {
        ans = max(ans, now);
        return;
    }
    for (int j=0; j<11; j++) {
        if (v[idx][j] == 0 || chk[j] == 1) continue;
        chk[j] = 1;
        go(idx + 1, now + v[idx][j]);
        chk[j] = 0;
    }
}

void solve(int CASE) {
    for (int i=0; i<11; i++) {
        for (int j=0; j<11; j++) {
            cin >> v[i][j];
        }
    }
    ans = 0;
    go(0, 0);
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