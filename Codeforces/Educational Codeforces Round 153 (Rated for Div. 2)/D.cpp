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

const int inf = 1e9;
int dp[110][110][5050];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    for (int i=0; i<110; i++)
        for (int j=0; j<110; j++)
            for (int k=0; k<5050; k++)
                dp[i][j][k] = inf;
    string s;
    cin >> s;
    int n = s.size();
    s.insert(s.begin(), ' ');
    dp[0][0][0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            for (int k=0; k<=i*i/2; k++) {
                if (j-1 >= 0) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][k] + (s[i] != '0'));
                if (k-j >= 0) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k - j] + (s[i] != '1'));
            }
        }
    }
    int cnt = count(s.begin(), s.end(), '0');
    cout << dp[n][cnt][cnt * (n-cnt) / 2] / 2 << '\n';
}