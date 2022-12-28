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

int v[20][20];
int p[3][30];
int ans, n, k, chk[10];

void simulation() {
    int cnt[] {0, 0, 0};
    int now[] {1, 1, 1};
    int can[] {0, 1};
    while (true) {
        if (can[0] > can[1]) swap(can[0], can[1]);
        int s = p[can[0]][now[can[0]]];
        int e = p[can[1]][now[can[1]]];
        now[can[0]]++;
        now[can[1]]++;
        if (s == 0 || e == 0) return;
        int nxt = 1^2^can[0]^can[1];
        if (v[s][e] == 0 || v[s][e] == 1) {
            cnt[can[1]]++;
            can[0] = nxt;
        }
        else if (v[s][e] == 2) {
            cnt[can[0]]++;
            can[1] = nxt;
        }
        if (cnt[0] >= k) {
            ans = 1;
            return;
        }
        else if (cnt[1] >= k || cnt[2] >= k) return;
    }
}

void go(int x) {
    if (x > n) {
        simulation();
        return;
    }
    for (int i=1; i<=n; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        p[0][x] = i;
        go(x + 1);
        p[0][x] = 0;
        chk[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=1; i<=20; i++) cin >> p[1][i];
    for (int i=1; i<=20; i++) cin >> p[2][i];
    go(1);
    cout << ans << '\n';
}