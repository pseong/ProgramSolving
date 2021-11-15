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

    string s[2];
    cin >> s[0] >> s[1];
    int diff='a'-'A';
    for(int i=0; i<s[0].size(); i++) {
        if(s[0][i]<'a') s[0][i] += diff;
    }
    for(int i=0; i<s[1].size(); i++) {
        if(s[1][i]<'a') s[1][i] += diff;
    }
    string a=s[0];
    string b=s[1];
    sort(s, s+2);
    if(s[0]==s[1]) cout << 0;
    else if(a==s[0]) cout << -1;
    else cout << 1;
}