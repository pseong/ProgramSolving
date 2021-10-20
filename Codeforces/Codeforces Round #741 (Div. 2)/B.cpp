#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

string s;
vector<int> ans;

bool find_p(int in) {
    bool ret=false;
    string str=to_string(in);
    for(int i=0; i<s.size(); i++) {
        if(ret) break;
        if(s[i]==str[0]) {
            int j=1;
            if(j==str.size()) {
                ret = true;
                break;
            }
            for(int x=i+1; x<s.size(); x++) {
                if(s[x]==str[j]) {
                    j++;
                    if(j==str.size()) {
                        ret = true;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    bool go[10010]{0};
    go[1] = 1;
    for(int i=2; i<=10000; i++) {
        if(go[i]==0) {
            for(int j=i*2; j<=10000; j+=i) {
                go[j] = 1;
            }
        }
    }
    for(int i=1; i<=10000; i++) {
        if(go[i]==1) {
            ans.push_back(i);
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int k;
        cin >> k >> s;
        string res=s;
        for(int i=0; i<ans.size(); i++) {
            if(find_p(ans[i])) {
                res = to_string(ans[i]);
                break;
            }
        }
        cout << res.size() << '\n' << res << '\n';
    }
}