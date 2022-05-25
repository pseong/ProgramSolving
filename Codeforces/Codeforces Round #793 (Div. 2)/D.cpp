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
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') cnt++;
        }
        if (cnt%2 == 1 || cnt == 0) {
            cout << "NO\n";
            continue;
        }
        int start = 0;
        if (cnt != n) {
            for (int i=0; i<n; i++) {
                if (s[i] == '1' && s[(i+1)%n] == '0') {
                    start = (i+1)%n;
                    break;
                }
            }
        }

        vector<pi> ans;
        int i = (start+1)%n;
        while (i != start) {
            int from = start;
            int to = i%n;
            while (s[to] == '0') {
                ans.push_back({from, to});
                from = to;
                to++;
                to %= n;
            }
            ans.push_back({from, to});
            i = to+1;
            i %= n;
        }
        cout << "YES\n";
        for (auto at : ans) {
            cout << at.first+1 << ' ' << at.second+1 << '\n';
        }
    }
}