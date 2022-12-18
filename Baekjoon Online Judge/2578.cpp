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

int v[6][6], chk[6][6];
pi p[26];

bool f() {
    int cnt = 0;
    for (int i=1; i<=5; i++) {
        bool ok = true;
        for (int j=1; j<=5; j++) {
            if (!chk[i][j]) ok = false;
        }
        if (ok) cnt++;
    }
    for (int j=1; j<=5; j++) {
        bool ok = true;
        for (int i=1; i<=5; i++) {
            if (!chk[i][j]) ok = false;
        }
        if (ok) cnt++;
    }
    if (chk[1][1] && chk[2][2] && chk[3][3] && chk[4][4] && chk[5][5]) cnt++;
    if (chk[1][5] && chk[2][4] && chk[3][3] && chk[4][2] && chk[5][1]) cnt++;
    return cnt >= 3;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5; j++) {
            cin >> v[i][j];
            p[v[i][j]] = {i, j};
        }
    }

    for (int i=1; i<=25; i++) {
        int a;
        cin >> a;
        chk[p[a].first][p[a].second] = 1;
        if (f()) {
            cout << i << '\n';
            return 0;
        }
    }
}