#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int mp[110][110];
vector<tuple<int, int, int, int>> ans;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(mp, 0, sizeof mp);
        ans.clear();

        int n, m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<m; j++) {
                mp[i][j+1] = s[j]-'0';
            }
        }

        if (mp[1][1] == 1) {
            cout << -1 << '\n';
            continue;
        }

        for (int a=1; a<=n; a++) {
            for (int b=m; b>=2; b--) {
                if (mp[a][b]) {
                    ans.push_back({a, b-1, a, b});
                }
            }
        }

        for (int a=n; a>=2; a--) {
            if (mp[a][1]) {
                ans.push_back({a-1, 1, a, 1});
            }
        }
 
        int ab = ans.size();
        cout << ab << '\n';
        for (auto au : ans) {
            cout << get<0>(au) << ' ';
            cout << get<1>(au) << ' ';
            cout << get<2>(au) << ' ';
            cout << get<3>(au) << ' ';
            cout << '\n';
        }
    }
}