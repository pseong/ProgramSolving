#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int MX=2000 + 10;
int w[MX][MX]{ 0 };
int s[MX][MX]{ 0 };
int o[MX][MX]{ 0 };

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int M, N;
    cin >> M >> N;
    for (int i=0; i<M; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            w[i][j] = s[j]-'0';
        }
    }
    for(int i=0; i<M; i++) {
        o[i][0] = w[i][0];
    }
    for (int j=1; j<N; j++) {
        for (int i=0; i<M; i++) {
            int mx=0;
            for(int k=i-1; k<i+2; k++) {
                if(k<0 || k>=M) continue;
                mx = max(mx, o[k][j-1]);
            }
            s[i][j] = mx;
            o[i][j] = s[i][j]+w[i][j];
        }
    }
    int res=0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            res = max(res, s[i][j]);
        }
    }
    cout << res;
    return 0;
}