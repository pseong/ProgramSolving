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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i=0; i<n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int x=0; x<2; x++) {
                for (int y=0; y<2; y++) {
                    int a = v[i][x] + v[j][y];
                    int b = max(v[i][x^1], v[j][y^1]);
                    if (a <= h && b <= w || a <= w && b <= h) ans = max(ans, v[i][0] * v[i][1] + v[j][0] * v[j][1]);
                }
            }
        }
    }
    cout << ans << '\n';
}