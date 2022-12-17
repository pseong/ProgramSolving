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

int n, v[500][500];
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};
tuple<int, int, int, int> in[500];

int cnt(int x, int y) {
    int ret = 0;
    for (int d=0; d<4; d++) {
        int r = x + dx[d];
        int c = y + dy[d];
        if (r < 1 || r > n || c < 1 || c > n) continue;
        if (v[r][c] == 0) ret++;
    }
    return ret;
}

bool comp(tuple<int, int, int, int>& l, tuple<int, int, int, int>& r) {
    if (get<0>(l) != get<0>(r)) return get<0>(l) > get<0>(r);
    else if (get<1>(l) != get<1>(r)) return get<1>(l) > get<1>(r);
    else if (get<2>(l) != get<2>(r)) return get<2>(l) < get<2>(r);
    else return get<3>(l) < get<3>(r);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int u=0; u<n*n; u++) {
        int x, a1, a2, a3, a4;
        cin >> x >> a1 >> a2 >> a3 >> a4;
        in[x] = {a1, a2, a3, a4};
        vector<tuple<int, int, int, int>> lst;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (v[i][j] == 0) {
                    int cnt1 = 0;
                    int cnt2 = 0;
                    for (int d=0; d<4; d++) {
                        int r = i + dx[d];
                        int c = j + dy[d];
                        if (r < 1 || r > n || c < 1 || c > n) continue;
                        if (v[r][c] == a1 || v[r][c] == a2 || v[r][c] == a3 || v[r][c] == a4) cnt1++;
                        else if (v[r][c] == 0) cnt2++;
                    }
                    lst.push_back({cnt1, cnt2, i, j});
                }
            }
        }
        sort(lst.begin(), lst.end(), comp);
        auto [p, p2, r, r2] = lst.front();
        v[r][r2] = x;
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int cnt = 0;
            auto [a1, a2, a3, a4] = in[v[i][j]];
            for (int d=0; d<4; d++) {
                int r = i + dx[d];
                int c = j + dy[d];
                if (r < 1 || r > n || c < 1 || c > n) continue;
                if (v[r][c] == a1 || v[r][c] == a2 || v[r][c] == a3 || v[r][c] == a4) cnt++;
            }
            if (cnt == 1) ans += 1;
            else if (cnt == 2) ans += 10;
            else if (cnt == 3) ans += 100;
            else if (cnt == 4) ans += 1000;
        }
    }
    cout << ans << '\n';
}