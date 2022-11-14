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

ll dp[130][130];
const ll inf = 101010101010101010;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, c;
    cin >> n >> m >> c;
    int k = c;
    k--;
    for (int i=1; i<110; i++) {
        dp[1][i] = i;
    }
    for (int i=2; i<110; i++) {
        for (int j=1; j<110; j++) {
            for (int k=1; k<=j; k++) {
                dp[i][j] += 1 + dp[i-1][k];
            }
            if (dp[i][j] >= inf) dp[i][j] = inf;
        }
    }
    if (dp[m][n] < k) { 
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans(m + 1);
    for (int i=1; i<=m; i++) {
        // 기존 위치 : m + 1 - i
        for (int j=1; j<n+1+i; j++) {
            if (dp[m-i+1][j-1] + 1 > k) {
                ans[i] = j - 1;
                if (j - 2 >= 0) k -= dp[m-i+1][j-2] + 1;
                break;
            }
        }
    }
    string a(n+m, 'a'); 
    for (int i=1; i<=m; i++) {
        a[n + i - 1 - ans[i]] = 'z';
    }
    cout << a << '\n';
}