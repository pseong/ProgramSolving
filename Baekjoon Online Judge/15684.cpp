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

int n, m, v[50][50];

bool chk() {
    for (int j=1; j<=m; j++) {
        int y = j;
        for (int i=1; i<=n; i++) {
            if (v[i][y] && v[i][y-1]) return false;
            if (v[i][y]) y++;
            else if (v[i][y-1]) y--;
        }
        if (y != j) return false;
    }
    return true;
}

pair<int, int> conv(int s) {
    int x = (s-1) / (m-1) + 1;
    int y = (s-1) % (m-1) + 1;
    return {x, y};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k;
    cin >> m >> k >> n;
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
    }
    if (chk()) {
        cout << 0 << '\n';
        return 0;
    }
    for (int s=1; s<=n*(m-1); s++) {
        auto [x, y] = conv(s);
        int tmp = v[x][y];
        v[x][y] = 1;
        if (chk()) {
            cout << 1 << '\n';
            return 0;
        }
        v[x][y] = tmp;
    }
    for (int s=1; s<=n*(m-1); s++) {
        for (int s2=s+1; s2<=n*(m-1); s2++) {
            auto [x, y] = conv(s);
            auto [x2, y2] = conv(s2);
            int tmp = v[x][y];
            int tmp2 = v[x2][y2];
            v[x][y] = 1;
            v[x2][y2] = 1;
            v[x][y] = 1;
            v[x2][y2] = 1;
            if (chk()) {
                cout << 2 << '\n';
                return 0;
            }
            v[x][y] = tmp;
            v[x2][y2] = tmp2;
        }
    }
    for (int s=1; s<=n*(m-1); s++) {
        for (int s2=s+1; s2<=n*(m-1); s2++) {
            for (int s3=s2+1; s3<=n*(m-1); s3++) {
                auto [x, y] = conv(s);
                auto [x2, y2] = conv(s2);
                auto [x3, y3] = conv(s3);
                int tmp = v[x][y];
                int tmp2 = v[x2][y2];
                int tmp3 = v[x3][y3];
                v[x][y] = 1;
                v[x2][y2] = 1;
                v[x3][y3] = 1;
                if (chk()) {
                    cout << 3 << '\n';
                    return 0;
                }
                v[x][y] = tmp;
                v[x2][y2] = tmp2;
                v[x3][y3] = tmp3;
            }
        }
    }
    cout << -1 << '\n';
}