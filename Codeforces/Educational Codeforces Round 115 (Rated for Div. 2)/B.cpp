#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(5, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<5; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=i+1; j<5; j++) {
            int one = 0;
            int two = 0;
            int common = 0;
            for (int k=0; k<n; k++) {
                if (v[k][i] && v[k][j]) common++;
                else if (v[k][i]) one++;
                else if (v[k][j]) two++;
            }
            if (one + two + common == n && one + common >= n/2 && two + common >= n/2) {
                yes();
                return;
            }
        }
    }
    no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}