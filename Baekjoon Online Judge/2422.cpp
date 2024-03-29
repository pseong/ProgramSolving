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

int chk[220][220];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        chk[a][b] = 1;
        chk[b][a] = 1;
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int k=j+1; k<=n; k++) {
                if (chk[i][j] || chk[i][k] || chk[j][k]) continue;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}