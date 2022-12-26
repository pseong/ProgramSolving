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

void rotate(vector<vector<int>>& v) {
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            int tmp = v[i][j];
            v[i][j] = v[j][4-i];
            v[j][4-i] = v[4-i][4-j];
            v[4-i][4-j] = v[4-j][i];
            v[4-j][i] = tmp;
        }
    }
}

int dk[] {-1, 1, 0, 0, 0, 0};
int dx[] {0, 0, -1, 1, 0, 0};
int dy[] {0, 0, 0, 0, -1, 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<vector<int>>> v(5, vector<vector<int>>(5, vector<int>(5)));
    for (int k=0; k<5; k++) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                cin >> v[k][i][j];
            }
        }
    }
    int ans = 1e9;
    vector<int> r(5);
    for (r[0]=0; r[0]<4; r[0]++) {
        for (r[1]=0; r[1]<4; r[1]++) {
            for (r[2]=0; r[2]<4; r[2]++) {
                for (r[3]=0; r[3]<4; r[3]++) {
                    for (r[4]=0; r[4]<4; r[4]++) {
                        auto cp = v;
                        for (int i=0; i<5; i++) {
                            for (int j=0; j<r[i]; j++) rotate(cp[i]);
                        }
                        auto m = cp;
                        vector<int> p{0, 1, 2, 3, 4};
                        do {
                            for (int i=0; i<5; i++) m[i] = cp[p[i]];
                            vector<ti> lst;
                            if (m[0][0][0] == 1) lst.push_back({0, 0, 0});
                            for (int i=0; i<(int)lst.size(); i++) {
                                auto [c, a, b] = lst[i];
                                vector<vector<vector<int>>> chk(5, vector<vector<int>>(5, vector<int>(5, -1)));
                                if (chk[c][a][b] != -1 || chk[c^4][a^4][b^4] != -1) continue;
                                queue<ti> q;
                                q.push({c, a, b});
                                chk[c][a][b] = 0;
                                while (q.size()) {
                                    auto [k, x, y] = q.front();
                                    q.pop();
                                    for (int d=0; d<6; d++) {
                                        int c = k + dk[d];
                                        int a = x + dx[d];
                                        int b = y + dy[d];
                                        if (c < 0 || c >= 5 || a < 0 || a >= 5 || b < 0 || b >= 5) continue;
                                        if (m[c][a][b] == 0 || chk[c][a][b] != -1) continue;
                                        chk[c][a][b] = chk[k][x][y] + 1;
                                        q.push({c, a, b});
                                    }
                                }
                                if (chk[4][4][4] != -1) {
                                    int e = min(ans, chk[4][4][4]);
                                    ans = min(ans, chk[4][4][4]);
                                }
                            }
                        } while (next_permutation(p.begin(), p.end()));
                    }
                }
            }
        }
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}