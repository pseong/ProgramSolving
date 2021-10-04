#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>=65&&s[i]<=90) {
            cout << s[i];
        } else if(s[i]==')') {
            while(st.top()!='(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else if(s[i]=='+'||s[i]=='-') {
            while(!st.empty() && (st.top()=='*'||st.top()=='/'||st.top()=='+'||st.top()=='-')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        } else if(s[i]=='*'||s[i]=='/') {
            while(!st.empty() && (st.top()=='*'||st.top()=='/')) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        } else {
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}