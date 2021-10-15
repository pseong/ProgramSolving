#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define pb push_back
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    string str;
    cin >> n >> str;
    double an[30]{0};
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    stack<double> st;
    for(int i=0; i<str.size(); i++) {
        if(str[i]>='A'&&str[i]<='Z') {
            st.push(an[str[i]-'A']);
        }
        else {
            double two=st.top();
            st.pop();
            double one=st.top();
            st.pop();
            if(str[i]=='*') {
                st.push(one*two);
            }
            else if(str[i]=='+') {
                st.push(one+two);
            }
            else if(str[i]=='-') {
                st.push(one-two);
            }
            else {
                st.push(one/two);
            }
        }
    }
    cout << fixed << setprecision(2) << st.top();
}