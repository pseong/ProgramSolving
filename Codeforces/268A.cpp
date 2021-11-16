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

    int n;
    cin >> n;
    int an[31]{0};
    int bn[31]{0};
    for(int i=1; i<=n; i++) {
        cin >> an[i] >> bn[i];
    }
    int ans=0;
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            if(an[k]==bn[i]) ans++;
        }
    }
    cout << ans;
}