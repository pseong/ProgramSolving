#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int an[50][50];
int bn[50][50];
int chk[50][50];

int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};
bool ok = true;
int n, m;

void dfs(int i, int j, int a, int b) {
    chk[i][j] = 1;
    for (int d=0; d<4; d++) {
        if (!ok) return;
        int x = i+dx[d];
        int y = j+dy[d];
        if (x < 1 || x > n || y < 1 || y > m) continue;
        if (chk[x][y]) continue;
        if (an[x][y] != a) continue;
        if (bn[x][y] != b) {
            ok = false;
            return;
        }
        dfs(x, y, a, b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> an[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> bn[i][j];
        }
    }

    int diff = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!ok) break;
            if (chk[i][j] == 0) {
                if (an[i][j] != bn[i][j]) {
                    diff++;
                    dfs(i, j, an[i][j], bn[i][j]);
                }
            }
            if (diff > 1) ok = false;
        }
    }

    if (!ok) cout << "NO\n";
    else cout << "YES\n";
}