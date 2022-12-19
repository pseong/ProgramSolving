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

int n, d, v[550][550];

void rotate() {
    int g = n / 2 + 1;
    vector<int> tmp(n / 2 + 1);
    for (int i=1; i<=n/2; i++) {
        tmp[i] = v[g-i][g];
    }
    for (int i=1; i<=n/2; i++) {
        v[g-i][g] = v[g-i][g+i];
    }
    for (int i=1; i<=n/2; i++) {
        v[g-i][g+i] = v[g][g+i];
    }
    for (int i=1; i<=n/2; i++) {
        v[g][g+i] = v[g+i][g+i];
    }
    for (int i=1; i<=n/2; i++) {
        v[g+i][g+i] = v[g+i][g];
    }
    for (int i=1; i<=n/2; i++) {
        v[g+i][g] = v[g+i][g-i];
    }
    for (int i=1; i<=n/2; i++) {
        v[g+i][g-i] = v[g][g-i];
    }
    for (int i=1; i<=n/2; i++) {
        v[g][g-i] = v[g-i][g-i];
    }
    for (int i=1; i<=n/2; i++) {
        v[g-i][g-i] = tmp[i];
    }
}

void solve(int CASE) {
    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    if (d > 0) d = d - 360;
    d = -d;
    for (int i=0; i<d/45; i++) {
        rotate();
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}