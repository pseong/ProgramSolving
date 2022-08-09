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

int dp[101010];

void solve(int CASE) {
    int n;
    cin >> n;
    n--;
    if (dp[n] == -1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n+1);
    for (int x=n; x>=0; x--) {
        int y = x;
        x = dp[y];
        int l = x;
        int r = y;
        while (l <= r) {
            ans[l] = r;
            ans[r] = l;
            l++;
            r--;
        }
    }
    for (int i=0; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    dp[1] = 0;
    for (int i=2; i<101010; i++) {
        for (int x=0; x*x<101010; x++) {
            if (i <= x*x) {
                int df = x*x - i;
                if (df > i) break;
                if (df == i) {
                    dp[i] = i;
                    break;
                }
                if (dp[df-1] != -1) {
                    dp[i] = df;
                    break;
                }
            }
        }
    }
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}