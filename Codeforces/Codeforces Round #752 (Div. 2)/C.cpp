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
        bool fail=false;
        for(int i=1; i<=n; i++) {
            if(an[i]%(i+1)>0) continue;
            fail = true;
            for(int j=1; j<i; j++) {
                if(an[i]%(i+1-j)>0) {
                    fail = false;
                    break;
                }
            }
            if(fail) break;
        }
        if(fail) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}