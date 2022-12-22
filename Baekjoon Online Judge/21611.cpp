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

int n, r, v[60][60];
int dx[] {0, 1, 0, -1};
int dy[] {-1, 0, 1, 0};
int ans[4];

pi next(int x, int y) {
    int a = x - (n + 1) / 2;
    int b = y - (n + 1) / 2;
    int m = max(abs(a), abs(b));
    if (a == -m) return {x, y - 1};
    if (b == m) return {x - 1, y};
    if (a == m) return {x, y + 1};
    else return {x + 1, y};
}

void clear() {
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;
    int a = x;
    int b = y - 1;
    while (y >= 1) {
        tie(x, y) = next(x, y);
        if (v[x][y]) swap(v[x][y], v[a][b]), tie(a, b) = next(a, b);
    }
}

void attack(int di, int si) {
    int dx[] {0, -1, 1, 0, 0};
    int dy[] {0, 0, 0, -1, 1};
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;
    for (int s=0; s<si; s++) {
        x += dx[di];
        y += dy[di];
        v[x][y] = 0;
    }
}

void boom() {
    int x = (n + 1) / 2;
    int y = (n + 1) / 2 - 1;
    int a = x;
    int b = y;
    int cnt = 1;
    while (y >= 1) {
        if (v[x][y] == 0) break;
        auto nxt = next(x, y);
        if (v[x][y] == v[nxt.first][nxt.second]) {
            cnt++;
        }
        else {
            if (cnt >= 4) {
                while (cnt--) {
                    ans[v[a][b]]++;
                    v[a][b] = 0;
                    tie(a, b) = next(a, b);
                }
            }
            else {
                cnt = 1;
                tie(a, b) = nxt;
            }
        }
        tie(x, y) = nxt;
    }
}

void change() {
    vector<int> lst;
    int x = (n + 1) / 2;
    int y = (n + 1) / 2 - 1;
    int cnt = 1;
    while (y >= 1) {
        if (v[x][y] == 0) break;
        auto nxt = next(x, y);
        if (v[x][y] == v[nxt.first][nxt.second]) {
            cnt++;
        }
        else {
            lst.push_back(cnt);
            lst.push_back(v[x][y]);
            cnt = 1;
        }
        tie(x, y) = nxt;
    }
    x = (n + 1) / 2;
    y = (n + 1) / 2 - 1;
    for (int i=0; i<min((int)lst.size(), n*n-1); i++) {
        v[x][y] = lst[i];
        tie(x, y) = next(x, y);
    }
}

void blizard(int di, int si) {
    attack(di, si);
    clear();
    vector<int> prev({ans[1], ans[2], ans[3]});
    do {
        prev = {ans[1], ans[2], ans[3]};
        boom();
        clear();
    } while (prev[0] != ans[1] || prev[1] != ans[2] || prev[2] != ans[3]);
    change();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> r;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=0; i<r; i++) {
        int d, s;
        cin >> d >> s;
        blizard(d, s);
    }
    cout << 1 * ans[1] + 2 * ans[2] + 3 * ans[3] << '\n';
}