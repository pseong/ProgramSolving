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

int n, m, k;

void rotate(vector<vector<int>>& v, int r, int c, int s) {
    for (int z=1; z<=s; z++) {
        int a = r - z;
        int b = c - z;
        int x = r + z;
        int y = c + z;
        int tmp = v[a][b];
        for (int i=a; i<x; i++) {
            v[i][b] = v[i+1][b];
        }
        for (int j=b; j<y; j++) {
            v[x][j] = v[x][j+1];
        }
        for (int i=x; i>a; i--) {
            v[i][y] = v[i-1][y];
        }
        for (int j=y; j>b; j--) {
            v[a][j] = v[a][j-1];
        }
        v[a][b+1] = tmp;
    }
}

struct S {
    int r, c, s;
    bool operator<(S& a) {
        if (r != a.r) return r < a.r;
        if (c != a.c) return c < a.c;
        return s < a.s;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    vector<S> lst(k);
    for (int i=0; i<k; i++) {
        cin >> lst[i].r >> lst[i].c >> lst[i].s;
    }
    sort(lst.begin(), lst.end());
    int ans = 1e9;
    do {
        auto at = v;
        for (int i=0; i<k; i++) {
            auto [r, c, s] = lst[i];
            rotate(at, r, c, s);
        }
        int mn = 1e9;
        for (int i=1; i<=n; i++) {
            int cnt = 0;
            for (int j=1; j<=m; j++) {
                cnt += at[i][j];
            }
            if (mn > cnt) mn = cnt;
        }
        if (ans > mn) ans = mn;
    } while (next_permutation(lst.begin(), lst.end()));
    cout << ans << '\n';
}