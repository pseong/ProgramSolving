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
        int n, m, k; cin >> n >> m >> k;
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        string ans;
        int prev = -1, go = -1, i = 0, j = 0;
        while (i < n && j < m) {
            if (go == k) {
                if (prev == 0) {
                    ans.push_back(b[j++]);
                    prev = 1;
                }
                else {
                    ans.push_back(a[i++]);
                    prev = 0;
                }
                go = 1;
            }
            else {
                if (a[i] < b[j]) {
                    ans.push_back(a[i++]);
                    if (prev != 0) prev = 0, go = 1;
                    else go++;
                }
                else {
                    ans.push_back(b[j++]);
                    if (prev != 1) prev = 1, go = 1;
                    else go++;
                }
            }
        }
        cout << ans << '\n';
    }
}