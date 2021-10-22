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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char> ans;
        for(int i=0; i<n; i++) {
            if(s[i]=='U') {
                ans.push_back('D');
            }
            else {
                ans.push_back(s[i]);
            }
        }
        for(char c : ans) {
            cout << c;
        }
        cout << '\n';
    }
}