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

int v[330][330];

void f(int a, int b, int x, int y) {
    if (a >= x || b >= y) return;
    int tmp = v[a][b];
    for (int j=b; j<y; j++) {
        v[a][j] = v[a][j+1];
    }
    for (int i=a; i<x; i++) {
        v[i][y] = v[i+1][y];
    }
    for (int j=y; j>b; j--) {
        v[x][j] = v[x][j-1];
    }
    for (int i=x; i>a; i--) {
        v[i][b] = v[i-1][b];
    }
    v[a+1][b] = tmp;
    f(a+1, b+1, x-1, y-1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=1; i<=r; i++) {
        f(1, 1, n, m);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}