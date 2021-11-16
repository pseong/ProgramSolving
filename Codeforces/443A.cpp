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
    getline(cin, s);
    set<char> st;
    for(int i=1; i<s.size(); i+=3) {
        if(s[i]!='{' && s[i]!='}') st.insert(s[i]);
    }
    cout << st.size();
}