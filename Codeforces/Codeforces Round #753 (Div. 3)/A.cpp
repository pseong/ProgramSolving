#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        string s, z;
        cin >> s >> z;
        int key[300]{0};
        for(int i=0; i<s.size(); i++) {
            key[s[i]] = i;
        }
        int ans=0;
        int pre=key[z[0]];
        for(int i=1; i<z.size(); i++) {
            ans += abs(pre-key[z[i]]);
            pre = key[z[i]];
        }
        cout << ans << '\n';
    }
}