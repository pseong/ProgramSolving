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

    map<string, int> mp;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int ans_num=0;
    string ans="";
    for(auto aut : mp) {
        if(aut.second>ans_num) {
            ans_num = aut.second;
            ans = aut.first;
        }
    }
    cout << ans;
}