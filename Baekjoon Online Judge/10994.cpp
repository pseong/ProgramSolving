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

int v[500][500];

void f(int a, int b, int x, int y) {
    for (int i=a; i<=x; i++) {
        v[i][b] = 1;
        v[i][y] = 1;
    }
    for (int j=b; j<=y; j++) {
        v[a][j] = 1;
        v[x][j] = 1;
    }
    if (a != x) f(a+2, b+2, x-2, y-2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a = n * 4 - 3;
    f(1, 1, a, a);
    for (int i=1; i<=a; i++) {
        for (int j=1; j<=a; j++) {
            if (v[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}