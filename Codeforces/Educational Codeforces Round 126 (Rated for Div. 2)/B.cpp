#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int mod = 32768;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int dp[32768]{ 0 };
        queue<pii> q;
        q.push({n, 0});
        dp[n] = 0;
        while (q.size()) {
            int p, cnt;
            tie(p, cnt) = q.front();
            if (p == 0) {
                cout << cnt << '\n';
                break;
            }
            q.pop();
            int v = (p+1) % mod;
            if (v == 0 && v != n) {
                cout << cnt+1 << '\n';
                break;
            }
            if (dp[v] == 0) {
                q.push({v, cnt+1});
                dp[v] = cnt+1;
            }
            v = (p*2) % mod;
            if (v == 0 && v != n) {
                cout << cnt+1 << '\n';
                break;
            }
            if (dp[v] == 0) {
                q.push({v, cnt+1});
                dp[v] = cnt+1;
            }
        }
    }
}