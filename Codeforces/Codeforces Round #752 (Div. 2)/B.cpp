#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
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
        if(n%2==0) {
            cout << "YES\n";
        }
        else {
            bool dec=false;
            for(int i=2; i<=n; i++) {
                if(an[i-1]>=an[i]) dec = true;
            }
            if(dec) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}