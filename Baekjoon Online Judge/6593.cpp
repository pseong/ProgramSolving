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

int chk[50][50][50];
char mp[50][50][50];

int dx[] {-1, 0, 0, 0, 0, 1};
int dy[] {0, -1, 0, 0, 1, 0};
int dz[] {0, 0, 1, -1, 0, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int l, r, c;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        memset(chk, 0, sizeof chk);
        memset(mp, 0, sizeof mp);
        queue<ti> q;
        for (int k=0; k<l; k++) {
            for (int i=0; i<r; i++) {
                string s;
                cin >> s;
                for (int j=0; j<c; j++) {
                    mp[i][j][k] = s[j];
                    if (s[j] == 'S') {
                        q.push({i, j, k});
                        chk[i][j][k] = 1;
                    }
                }
            }
        }
        while (q.size()) {
            int t, e, f;
            tie(t, e, f) = q.front();
            q.pop();
            for (int d=0; d<6; d++) {
                int x = t + dx[d];
                int y = e + dy[d];
                int z = f + dz[d];
                if (x < 0 || x >= r || y < 0 || y >= c || z < 0 || z >= l) continue;
                if (chk[x][y][z]) continue;
                if (mp[x][y][z] == '#') continue;
                chk[x][y][z] = chk[t][e][f] + 1;
                if (mp[x][y][z] == 'E') {
                    cout << "Escaped in " << chk[x][y][z] - 1 << " minute(s).\n";
                    goto g;
                }
                q.push({x, y, z});
            }
        }
        cout << "Trapped!\n";
        g:
        continue;
    }
}