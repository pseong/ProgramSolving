#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n;
string s;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> s;
        bool fin=false;
        for(int i=0; i<n; i++) {
            if(s[i]!='?') {
                int go=i;
                fin = true;
                while(go-1>=0 && s[go-1]=='?') {
                    s[go-1] = s[go]^('B'^'R');
                    go--;
                }
                go = i;
                while(go+1<n && s[go+1]=='?') {
                    s[go+1] = s[go]^('B'^'R');
                    go++;
                }
            }
        }
        if(!fin) {
            s[0] = 'B';
            cout << 'B';
            for(int i=1; i<n; i++) {
                s[i] = s[i-1]^('B'^'R');
                cout << s[i];
            }
        }
        else cout << s;
        cout << '\n';
    }
}