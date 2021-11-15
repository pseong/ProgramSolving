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

    int l=0, u=0;
    string s;
    cin >> s;
    int diff='a'-'A';
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a') l++;
        else u++;
    }
    for(int i=0; i<s.size(); i++) {
        if(l>=u) {
            if(s[i]<'a') s[i] += diff;
        }
        else {
            if(s[i]>='a') s[i] -= diff;
        }
    }
    cout << s;
}