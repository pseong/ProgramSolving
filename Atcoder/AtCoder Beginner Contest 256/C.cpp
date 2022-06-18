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
    int ans = 0;
    int h[3], w[3];
    cin >> h[0] >> h[1] >> h[2];
    cin >> w[0] >> w[1] >> w[2];
    for (int i=1; i<=h[0]; i++) {
        for (int j=1; j<=h[0]; j++) {
            if (i+j >= h[0]) continue;
            int k = h[0] - i - j;

            for (int x=1; x<=h[1]; x++) {
                for (int y=1; y<=h[1]; y++) {
                    if (x+y >= h[1]) continue;
                    int z = h[1] - x - y;

                    int u = w[0]-i-x;
                    int v = w[1]-j-y;
                    int m = w[2]-k-z;
                    if (u < 1 || v < 1 || m < 1 || u + v + m != h[2]) continue;
                    ans++;
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}