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
    int ans=0;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        stack<char> st;
        for(int i=0; i<str.size(); i++) {
            if(st.empty()) {
                st.push(str[i]);
                continue;
            }
            if(st.top()==str[i]) {
                st.pop();
            }
            else {
                st.push(str[i]);
            }
        }
        if(st.empty()) ans++;
    }
    cout << ans;
}