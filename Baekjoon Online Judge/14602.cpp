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

int dx[] {-1, 1, 0, 0, 0};
int dy[] {0, 0, -1, 1, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 1e9;
    for (int x1=2; x1<=n-1; x1++) {
        for (int y1=2; y1<=n-1; y1++) {
            for (int x2=2; x2<=n-1; x2++) {
                for (int y2=2; y2<=n-1; y2++) {
                    for (int x3=2; x3<=n-1; x3++) {
                        for (int y3=2; y3<=n-1; y3++) {
                            vector<vector<int>> chk(n + 1, vector<int>(n + 1));
                            bool ok = true;
                            int res = 0;
                            for (int d=0; d<5; d++) {
                                res += v[x1 + dx[d]][y1 + dy[d]];
                                res += v[x2 + dx[d]][y2 + dy[d]];
                                res += v[x3 + dx[d]][y3 + dy[d]];
                                if (++chk[x1 + dx[d]][y1 + dy[d]] >= 2) ok = false;
                                if (++chk[x2 + dx[d]][y2 + dy[d]] >= 2) ok = false;
                                if (++chk[x3 + dx[d]][y3 + dy[d]] >= 2) ok = false;
                            }
                            if (ok) ans = min(ans, res);
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}