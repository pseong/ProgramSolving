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

    string str;
    stack<char> st;
    cin >> str;
    
    ll ans=0;
    int res=1;
    bool fail=false;

    for(int i=0; i<str.size(); i++) {
        if(str[i]=='(') {
            res *= 2;
            st.push('(');
        }
        else if(str[i]=='[') {
            res *= 3;
            st.push('[');
        }
        else if(str[i]==')' && (st.empty() || st.top()!='(')) {
            fail = true;
            break;
        }
        else if(str[i]==']' && (st.empty() || st.top()!='[')) {
            fail = true;
            break;
        }
        else if(str[i]==')') {
            if(str[i-1]=='(')
                ans += res;
            else {
                cout << "ddd\n";
            }
            st.pop();
            res /= 2;
        }
        else if(str[i]==']') {
            if(str[i-1]=='[')
                ans += res;
            else {
                cout << "dsgsag\n";
            }
            st.pop();
            res /= 3;
        }
    }

    if(fail || !st.empty()) {
        cout << 0 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}