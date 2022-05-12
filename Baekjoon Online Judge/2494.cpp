#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }


int dp[10101][10];
int p[10101][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string an, bn;
    for (int i=0; i<=10000; i++) {
        for (int j=0; j<10; j++) {
            dp[i][j] = 1000000000;
        }
    }
    dp[0][0] = 0;
    cin >> an >> bn;
    an.insert(an.begin(), 0);
    bn.insert(bn.begin(), 0);
    for (int i=1; i<=n; i++) {
        for (int j=0; j<10; j++) {
            int lcnt = (an[i]-bn[i]+j+10)%10;
            int rcnt = 10 - lcnt;
            if (dp[i][j] > dp[i-1][j]+lcnt) {
                dp[i][j] = dp[i-1][j] + lcnt;
                p[i][j] = -lcnt;
            }
            if (dp[i][(j+rcnt)%10] > dp[i-1][j]+rcnt) {
                dp[i][(j+rcnt)%10] = dp[i-1][j]+rcnt;
                p[i][(j+rcnt)%10] = rcnt;
            }
        }
    }
    int tmp = dp[n][0];
    int idx = 0;
    for (int i=0; i<10; i++) {
        if (dp[n][i] < tmp) {
            tmp = dp[n][i];
            idx = i;
        }
    }
    int go = idx;
    stack<int> st;
    for (int i=n; i>=1; i--) {
        st.push(p[i][go]);
        if (p[i][go] > 0) {
            go = (go - p[i][go] + 10) % 10;
        }
    }
    cout << tmp << '\n';
    for (int i=1; i<=n; i++) {
        cout << i << ' ' << st.top() << '\n';
        st.pop();
    }
}