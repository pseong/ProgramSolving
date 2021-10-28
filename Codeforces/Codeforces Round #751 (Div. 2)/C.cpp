#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
 
const int N=200000;
int n, an[N+10];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        int ans=0;
        for(int k=0; k<30; k++) {
            int cnt=0;
            for(int i=1; i<=n; i++) {
                if(an[i]&(1<<k)) cnt++;
            }
            ans = __gcd(ans, cnt);
        }
        if(!ans) {
            for(int i=1; i<=n; i++) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }
        for(int i=1; i<=ans; i++) {
            if(ans%i==0) cout << i << ' ';
        }
        cout << '\n';
    }
}