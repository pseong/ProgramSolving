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

int cnt[11][11][11][11];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    for (int i=0; i<n; i++) {
        vector<vector<int>> q(4, vector<int>(2));
        for (int j=0; j<4; j++) {
            q[j][0] = 10;
            q[j][1] = v[i][j] - '0';
        }

        for (int a=0; a<2; a++) {
            for (int b=0; b<2; b++) {
                for (int c=0; c<2; c++) {
                    for (int d=0; d<2; d++) {
                        cnt[q[0][a]][q[1][b]][q[2][c]][q[3][d]]++;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            vector<vector<int>> g(4, vector<int>());
            for (int k=0; k<4; k++) {
                if (v[i][k] == v[j][k]) g[k].push_back(v[i][k] - '0');
                else {
                    g[k].push_back(10);
                    g[k].push_back(v[i][k] - '0');
                    g[k].push_back(v[j][k] - '0');
                }
            }
            for (int a=0; a<(int)g[0].size(); a++) {
                for (int b=0; b<(int)g[1].size(); b++) {
                    for (int c=0; c<(int)g[2].size(); c++) {
                        for (int d=0; d<(int)g[3].size(); d++) {
                            int count = 0;
                            if (g[0].size() > 1 && g[0][a] != 10) count++;
                            if (g[1].size() > 1 && g[1][b] != 10) count++;
                            if (g[2].size() > 1 && g[2][c] != 10) count++;
                            if (g[3].size() > 1 && g[3][d] != 10) count++;
                            if (count % 2 == 1) {
                                ans -= cnt[g[0][a]][g[1][b]][g[2][c]][g[3][d]];
                            }
                            else ans += cnt[g[0][a]][g[1][b]][g[2][c]][g[3][d]];
                        }
                    }
                }
            }
        }
    }
    cout << ans / 3 << '\n';
}