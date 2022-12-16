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

int dp[110][110][110];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s[3];
    for (int i=0; i<3; i++) {
        cin >> s[i];
        s[i].insert(s[i].begin(), '0');
    }
    for (int i=1; i<(int)s[0].size(); i++) {
        for (int j=1; j<(int)s[1].size(); j++) {
            for (int k=1; k<(int)s[2].size(); k++) {
                if (s[0][i] == s[1][j] && s[1][j] == s[2][k]) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + 1);
                }
                else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
    }
    cout << dp[s[0].size()-1][s[1].size()-1][s[2].size()-1] << '\n';
}