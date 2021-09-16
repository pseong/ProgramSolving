#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(true) {
        string s;
        getline(cin, s);
        if(s==".") break;
        stack<char> st;
        bool ans=true;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='[') st.push('[');
            else if(s[i]=='(') st.push('(');
            else if(s[i]==')') {
                if(st.empty()||st.top()!='(') {
                    ans = false;
                    break;
                }
                st.pop();
            } else if(s[i]==']') {
                if(st.empty()||st.top()!='[') {
                    ans = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()) ans = false;
        cout << (ans ? "yes" : "no") << '\n';
    }
}