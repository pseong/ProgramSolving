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

int n, m, ans;
string v[20];

void go(int i, int j, int now) {
    if (j >= m) {
        j = 0;
        i++;
        if (i >= n) return;
    }
    int c = 0;
    while (true) {
        int dx[] {-c, c, 0, 0};
        int dy[] {0, 0, -c, c};
        bool ok = true;
        for (int d=0; d<4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x < 0 || x >= n || y < 0 || y >= m) {
                ok = false;
                break;
            }
            if (v[x][y] == '.') ok = false;
        }
        if (!ok) {
            for (int k=0; k<c; k++) {
                int dx[] {-k, k, 0, 0};
                int dy[] {0, 0, -k, k};
                for (int d=0; d<4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    v[x][y] = '#';
                }
            }
            break;
        }
        else {
            if (now) {
                ans = max(ans, now * (c * 4 + 1));
            }
            else {
                for (int d=0; d<4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    v[x][y] = '.';
                }
                go(i, j+1, c * 4 + 1);
            }
        }
        c++;
    }
    go(i, j+1, now);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    go(0, 0, 0);
    cout << ans << '\n';
}