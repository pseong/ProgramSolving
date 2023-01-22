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
    vector<vector<int>> v(n, vector<int>(n));
    int now[2] {1, n*n};
    int cur = 0;
    for (int i=0; i<n; i++) {
        if (i%2 == 0) {
            for (int j=0; j<n; j++) {
                v[i][j] = now[cur];
                if (cur == 0) now[cur]++;
                else now[cur]--;
                cur ^= 1;
            }
        }
        else {
            for (int j=n-1; j>=0; j--) {
                v[i][j] = now[cur];
                if (cur == 0) now[cur]++;
                else now[cur]--;
                cur ^= 1;
            }
        }
    }
    for (int i=0; i<n; i++) {
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