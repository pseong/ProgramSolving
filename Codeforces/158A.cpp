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

    int n, k, an[100]{0};
    cin >> n >> k;
    int ans=0;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for(int i=1; i<=n; i++) {
        if(an[i]>=an[k] && an[i]>0) {
            ans++;
        }
    }
    cout << ans;
}