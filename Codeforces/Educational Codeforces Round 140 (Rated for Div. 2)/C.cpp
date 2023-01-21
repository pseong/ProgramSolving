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

ll v[110][110], dp[110][110]; // 0 : 전부 0, 1 : 전부 1, 2 : 두 종류, 3 : 상관 없음
const ll mod = 998244353;

bool chk(int i, int j) {
    for (int k=1; k<=i; k++) {
        if (v[k][i] == 0) continue;
        else if (v[k][i] == 1 && k <= j) return false;
        else if (v[k][i] == 2 && k > j) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    if (v[1][1] != 2) dp[1][0] = 2;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            for (int k : {i, j}) {
                if (chk(i+1, k)) {
                    dp[i+1][k] += dp[i][j];
                    dp[i+1][k] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i=0; i<=n; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << '\n';
}