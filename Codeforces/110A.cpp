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

    string s;
    cin >> s;
    int luck=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='4' || s[i]=='7') {
            luck++;
        }
    }
    string s2=to_string(luck);
    bool luck2 = true;
    for(int i=0; i<s2.size(); i++) {
        if(s2[i]!='4' && s2[i]!='7') {
            luck2 = false;
            break;
        }
    }
    if(luck2) cout << "YES";
    else cout << "NO";
}