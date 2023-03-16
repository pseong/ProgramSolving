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

int v[1024][1024];

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    cout << n * m << '\n';
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int now = 0;
    for (int i=0; i<8; i+=2) {
        for (int j=0; j<8; j+=2) {
            v[i][j] = now++;
            v[i][j+1] = now++;
            v[i+1][j] = now++;
            v[i+1][j+1] = now++;
        }
    }

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cout << v[i][j] << '\n';
        }
    }
    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}