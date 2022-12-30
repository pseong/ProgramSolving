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

int n, chk[100][100];
double ans, p[4];
int dx[] {0, 0, 1, -1};
int dy[] {1, -1, 0, 0};

void go(int idx, int x, int y, double per) {
    if (idx == n) {
        ans += per;
        return;
    }
    for (int d=0; d<4; d++) {
        int a = x + dx[d];
        int b = y + dy[d];
        if (chk[a][b]) continue;
        chk[a][b] = 1;
        go(idx + 1, a, b, per * p[d]);
        chk[a][b] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<4; i++) {
        cin >> p[i];
        p[i] = p[i] / 100;
    }
    chk[50][50] = 1;
    go(0, 50, 50, 1);
    cout << fixed << setprecision(9) << ans << '\n';
}