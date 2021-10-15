#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

string n;
vector<string> v;
set<string> ans;
void dfs(int s, int e) {
    if(e-s+1==n.size()) {
        string res="";
        for(string& s : v) {
            res += s;
        }
        ans.insert(res);
        return;
    }
    if(s>0) {
        v.push_back(n.substr(s-1, e-s+2));
        dfs(s-1, e);
        v.pop_back();
    }
    if(e<n.size()-1) {
        v.push_back(n.substr(s, e-s+2));
        dfs(s, e+1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n.size(); i++) {
        v.push_back(to_string(n[i]));
        dfs(i, i);
        v.pop_back();
    }
    cout << ans.size();
}