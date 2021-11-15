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
    int cnt[4]{0};
    for(int i=0; i<s.size(); i+=2) {
        int a=s[i]-'0';
        cnt[a]++;
    }
    string ans="";
    while(cnt[1]--) {
        ans.push_back('1');
    }
    while(cnt[2]--) {
        ans.push_back('2');
    }
    while(cnt[3]--) {
        ans.push_back('3');
    }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if(i!=ans.size()-1) cout << '+';
    }
}