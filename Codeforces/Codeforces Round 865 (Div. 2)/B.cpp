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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    int now = n;
    for (int i=0; i<n; i+=2) {
        v[1][i] = now--;
        v[0][i+1] = now--;
    }
    v[0][0] = 2*n;
    v[1][n-1] = 2*n - 1;
    now = 2*n - 2;
    for (int i=1; i<n-1; i+=2) {
        v[1][i] = now--;
        v[0][i+1] = now--;
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) {
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