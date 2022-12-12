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

vector<int> v[55];
int dp[55][1010];
const int mod = 10007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, h;
    cin >> n >> m >> h;
    for (int i=0; i<=n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int a;  
        while (ss >> a) v[i].push_back(a);
    }
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=h; j++) {
            dp[i][j] = dp[i-1][j];
        }
        for (int x : v[i]) {
            for (int j=0; j<=h; j++) {
                if (j-x >= 0) dp[i][j] += dp[i-1][j-x];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][h] << '\n';
}