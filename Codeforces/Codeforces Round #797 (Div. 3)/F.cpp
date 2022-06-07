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
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
            v[i]--;
        }

        vector<int> chk(n+1);
        vector<vector<int>> cycles;
        for (int i=0; i<n; i++) {
            if (chk[i] == 0) {
                vector<int> now;
                int go = i;
                now.push_back(i);
                chk[go] = 1;
                while (chk[v[go]] == 0) {
                    go = v[go];
                    chk[go] = 1;
                    now.push_back(go);
                }
                cycles.push_back(now);
            }
        }
        vector<int> gcds;
        for (auto& now : cycles) {
            string tmp = s;
            string prev = tmp;
            int cnt = 0;
            do {
                cnt++;
                for (int i=0; i<(int) now.size(); i++) {
                    tmp[now[i]] = prev[v[now[i]]];
                }
                prev = tmp;
            } while (tmp != s);
            gcds.push_back(cnt);
        }

        ll ans = 1;
        for (auto at : gcds) {
            ans = ans * at / gcd(ans, at);
        }
        cout << ans << '\n';
    }
}