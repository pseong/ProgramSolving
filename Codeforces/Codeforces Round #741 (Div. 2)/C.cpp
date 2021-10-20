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
        int n;
        string s;
        cin >> n >> s;
        bool solve=false;
        for(int i=0; i<n; i++) {
            if(s[i]=='0') {
                solve = true;
                if(i<=(n-1)/2) {
                    cout << i+1 << ' ' << n << ' ' << i+2 << ' ' << n << '\n';
                }
                else {
                    cout << 1 << ' ' << i+1 << ' ' << 1 << ' ' << i << '\n';
                }
                break;
            }
        }
        if(!solve) {
            cout << 1 << ' ' << n-1 << ' ' << 2 << ' ' << n << '\n';
        }
    }
}