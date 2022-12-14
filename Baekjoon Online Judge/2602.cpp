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

vector<int> dp;
int ans, n;
string go, s[2];

void f(int now) {
    for (char c : go) {
        vector<int> tmp(n);
        for (int i=0; i<n; i++) {
            if (s[now][i] == c) {
                for (int j=0; j<i; j++) {
                    tmp[i] += dp[j];
                }
            }
        }
        dp = tmp;
        now ^= 1;
    }
    for (int i=0; i<n; i++) {
        ans += dp[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> go >> s[0] >> s[1];
    s[0].insert(s[0].begin(), '0');
    s[1].insert(s[1].begin(), '0');
    n = s[0].size();

    dp.assign(n, 0);
    dp[0] = 1;
    f(0);
    
    dp.assign(n, 0);
    dp[0] = 1;
    f(1);

    cout << ans << '\n';
}