#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n;
string s;
map<char, int> x;
char x2[]{'B', 'R'};
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    x['B'] = 0;
    x['R'] = 1;
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> s;
        bool fin=false;
        for(int i=0; i<n; i++) {
            if(s[i]!='?') {
                int go=i;
                fin = true;
                int base=x[s[go]];
                while(go-1>=0 && s[go-1]=='?') {
                    base ^= 1;
                    s[go-1] = x2[base];
                    go--;
                }
                go = i;
                base=x[s[go]];
                while(go+1<n && s[go+1]=='?') {
                    base ^= 1;
                    s[go+1] = x2[base];
                    go++;
                }
            }
        }
        if(!fin) {
            int base=0;
            for(int i=0; i<n; i++) {
                cout << x2[base];
                base ^= 1;
            }
        }
        else cout << s;
        cout << '\n';
    }
}