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
    set<char> st;
    for(char c : s) {
        st.insert(c);
    }
    if(st.size()&1) {
        cout << "IGNORE HIM!";
    }
    else {
        cout << "CHAT WITH HER!";
    }
}