#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<string> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        vector<int> sum, diff;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] == 'B') {
                    sum.push_back(-i-j-2);
                    diff.push_back(-i+j);
                }
            }
        }

        sort(sum.begin(), sum.end());
        sort(diff.begin(), diff.end());
        int ans_a = -1;
        int ans_b = -1;
        ll summ = -1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int cal = max({abs(i+j+sum.back()), abs(i+j+sum.front()), abs(i-j+diff.back()), abs(i-j+diff.front())});
                if (summ == -1 || summ > cal) {
                    ans_a = i;
                    ans_b = j;
                    summ = cal;
                }
            }
        }
        cout << ans_a << ' ' << ans_b << '\n';
    }
}