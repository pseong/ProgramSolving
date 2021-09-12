#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        stack<char> st;
        string s;
        cin >> s;

        bool isvps = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            } else {
                if(st.size() == 0) {
                    isvps = 0;
                    break;
                }
                if(st.top() == '(') {
                    st.pop();
                } else {
                    isvps = 0;
                    break;
                }
            }
        }
        if(st.size() > 0) isvps = false;
        cout << ((isvps) ? "YES" : "NO") << '\n';
    }
}