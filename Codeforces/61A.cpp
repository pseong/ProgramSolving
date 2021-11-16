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

    string s1, s2;
    cin >> s1 >> s2;
    string ans="";
    for(int i=0; i<s1.size(); i++) {
        ans.push_back((s1[i]-'0')^(s2[i]-'0')+'0');
    }
    cout << ans;
}