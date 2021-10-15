#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int go[300]{0};
vector<pii> v;
vector<string> ans;
string str;

void dfs(int idx) {
    if(idx==v.size()) {
        string res="";
        bool no_erase=true;
        for(int i=0; i<str.size(); i++) {
            if(go[i]==0) res.push_back(str[i]);
            else {
                no_erase=false;
            }
        }
        if(no_erase) return;
        ans.push_back(res);
        return;
    }
    dfs(idx+1);
    go[v[idx].F] = 1;
    go[v[idx].S] = 1;
    dfs(idx+1);
    go[v[idx].F] = 0;
    go[v[idx].S] = 0;
    return;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> str;
    stack<int> st;
    for(int i=0; i<str.size(); i++) {
        if(str[i]=='(') {
            st.push(i);
        }
        else if(str[i]==')') {
            int a=st.top();
            st.pop();
            v.push_back({a, i});
        }
    }
    dfs(0);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(string& s : ans) {
        cout << s << '\n';
    }
}