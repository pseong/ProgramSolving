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

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans=0;
    for(int i=0; i<s.size()-1; i++) {
        if(s[i]==s[i+1]) ans++;
    }
    cout << ans;
}