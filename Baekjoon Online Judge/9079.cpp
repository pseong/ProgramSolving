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
    vector<vector<char>> v(3, vector<char>(3, '.'));
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 1e9;
    for (int k=0; k<(1<<8); k++) {
        auto cp = v;
        if (k & (1<<0)) for (int i=0; i<3; i++) cp[i][0] ^= 'H'^'T';
        if (k & (1<<1)) for (int i=0; i<3; i++) cp[i][1] ^= 'H'^'T';
        if (k & (1<<2)) for (int i=0; i<3; i++) cp[i][2] ^= 'H'^'T';
        if (k & (1<<3)) for (int i=0; i<3; i++) cp[0][i] ^= 'H'^'T';
        if (k & (1<<4)) for (int i=0; i<3; i++) cp[1][i] ^= 'H'^'T';
        if (k & (1<<5)) for (int i=0; i<3; i++) cp[2][i] ^= 'H'^'T';
        if (k & (1<<6)) for (int i=0; i<3; i++) cp[i][i] ^= 'H'^'T';
        if (k & (1<<7)) for (int i=0; i<3; i++) cp[i][2-i] ^= 'H'^'T';
        bool ok = true;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (cp[i][j] != cp[0][0]) ok = false;
            }
        }
        int cnt = 0;
        for (int i=0; i<8; i++) if (k & (1<<i)) cnt++;
        if (ok) ans = min(ans, cnt);
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
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