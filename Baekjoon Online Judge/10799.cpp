#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    stack<char> st;
    string s;
    cin >> s;

    int bar = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
            bar++;
        }
        else {
            bar--;
            if(s[i - 1] == '(') {
                count += bar;
                st.pop();
            } else {
                count++;
            }
        }
    }
    cout << count;
}