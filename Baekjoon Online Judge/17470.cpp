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

vector<vector<int>> v[4];
int n, m, r;

void rotate(int k) {
    vector<vector<int>> tmp(m/2, vector<int>(n/2));
    for (int i=0; i<n/2; i++) {
        for (int j=0; j<m/2; j++) {
            tmp[j][n/2-1-i] = v[k][i][j];
        }
    }
    v[k] = tmp;
}

void revh(int k) {
    for (int i=0; i<n/2; i++) {
        for (int j=0; j<m/4; j++) {
            swap(v[k][i][j], v[k][i][m/2-1-j]);
        }
    }
}

void revv(int k) {
    for (int i=0; i<n/4; i++) {
        for (int j=0; j<m/2; j++) {
            swap(v[k][i][j], v[k][n/2-1-i][j]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> r;
    vector<vector<int>> tmp(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> tmp[i][j];
        }
    }
    for (int i=0; i<4; i++) {
        v[i].resize(n/2, vector<int>(m/2));
    }
    for (int i=0; i<n/2; i++) {
        for (int j=0; j<m/2; j++) {
            v[0][i][j] = tmp[i][j];
            v[1][i][j] = tmp[i][j+m/2];
            v[2][i][j] = tmp[i+n/2][j];
            v[3][i][j] = tmp[i+n/2][j+m/2];
        }
    }
    vector<vector<int>> p({{0, 1}, {2, 3}});
    int x = 0;
    int y = 3;
    for (int R=0; R<r; R++) {
        int w;
        cin >> w;
        if (w == 1) {
            swap(p[0][0], p[1][0]);
            swap(p[0][1], p[1][1]);
            if (x == 0 || x == 2) x ^= 2;
            if (y == 0 || y == 2) y ^= 2;
        }
        else if (w == 2) {
            swap(p[0][0], p[0][1]);
            swap(p[1][0], p[1][1]);
            if (x == 1 || x == 3) x ^= 1^3;
            if (y == 1 || y == 3) y ^= 1^3;
        }
        else if (w == 3) {
            int tmp = p[0][0];
            p[0][0] = p[1][0];
            p[1][0] = p[1][1];
            p[1][1] = p[0][1];
            p[0][1] = tmp;
            x = (x + 1) % 4;
            y = (y + 1) % 4;
        }
        else if (w == 4) {
            int tmp = p[0][0];
            p[0][0] = p[0][1];
            p[0][1] = p[1][1];
            p[1][1] = p[1][0];
            p[1][0] = tmp;
            x = (x + 3) % 4;
            y = (y + 3) % 4;
        }
        else if (w == 5) {
            int tmp = p[0][0];
            p[0][0] = p[1][0];
            p[1][0] = p[1][1];
            p[1][1] = p[0][1];
            p[0][1] = tmp;
        }
        else if (w == 6) {
            int tmp = p[0][0];
            p[0][0] = p[0][1];
            p[0][1] = p[1][1];
            p[1][1] = p[1][0];
            p[1][0] = tmp;
        }
    }
    int nx = 0;
    int ny = 3;
    while (nx != x) {
        nx = (nx + 1) % 4;
        ny = (ny + 1) % 4;
        for (int k=0; k<4; k++) rotate(k);
        swap(n, m);
    }
    if (ny != y) {
        if (y == 1 || y == 3) for (int k=0; k<4; k++) revh(k);
        if (y == 0 || y == 2) for (int k=0; k<4; k++) revv(k);
    }
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i=0; i<n/2; i++) {
        for (int j=0; j<m/2; j++) {
            ans[i][j] = v[p[0][0]][i][j];
            ans[i][j+m/2] = v[p[0][1]][i][j];
            ans[i+n/2][j] = v[p[1][0]][i][j];
            ans[i+n/2][j+m/2] = v[p[1][1]][i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}