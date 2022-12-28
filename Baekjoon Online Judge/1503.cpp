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

int vis[1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        vis[a] = 1;
    }
    int ans = 1e9;
    for (int i=1; i<=1001; i++) {
        if (vis[i]) continue;
        for (int j=1; j<=1001; j++) {
            if (vis[j]) continue;
            for (int k=1; k<=1001; k++) {
                if (vis[k]) continue;
                ans = min(ans, abs(n - i * j * k));
                if (i * j * k >= n) break;
            }
            if (i * j >= n) break;
        }
        if (i >= n) break;
    }
    cout << ans << '\n';
}