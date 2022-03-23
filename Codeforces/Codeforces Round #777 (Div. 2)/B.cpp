#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int mp[110][110];
int chk[110][110];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(mp, 0, sizeof mp);
        memset(chk, 0, sizeof chk);

        int n, m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<m; j++) {
                mp[i][j+1] = s[j]-'0';
            }
        }

        bool elegant = true;
        for (int i=1; i<=n-1; i++) {
            for (int j=1; j<=m-1; j++) {
                int a = i;
                int b = j;
                if (mp[a][b]+mp[a+1][b]+mp[a][b+1]+mp[a+1][b+1]==3) {
                    elegant = false;
                    break;
                }
            }
        }

        if (elegant) cout << "YES\n";
        else cout << "NO\n";
    }
}