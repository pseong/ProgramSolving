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

int n, m, r, v[330][330];

void rotate(int k) {
    int a = k;
    int b = k;
    int x = n - k + 1;
    int y = m - k + 1;
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
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> r;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    int g = min(n/2, m/2);
    for (int k=1; k<=g; k++) {
        int cnt = n*2 + m*2 - 4 - 8*(k-1);
        for (int i=0; i<r%cnt; i++) {
            rotate(k);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}