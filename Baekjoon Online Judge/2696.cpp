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

    int T;
    cin >> T;
    while(T--) {
        int m;
        cin >> m;
        multiset<int> am;
        vector<int> ans;
        for(int i=1; i<=m; i++) {
            int a;
            cin >> a;
            am.insert(a);
            if(i&1) {
                auto it=am.begin();
                for(int j=0; j<am.size()/2; j++) it++;
                ans.push_back(*it);
            }
        }
        cout << ans.size() << '\n';
        for(int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}