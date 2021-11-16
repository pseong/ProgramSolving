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

    set<char> st;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a') s[i] -= 'a'-'A';
        st.insert(s[i]);
    }
    if(st.size()==26) cout << "YES";
    else cout << "NO";
}