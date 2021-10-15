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
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        stack<char> st1;
        stack<char> st2;
        for(int j=0; j<s.size(); j++) {
            if(s[j]=='-') {
                if(!st1.empty()) st1.pop();
            }
            else if(s[j]=='<') {
                if(!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            else if(s[j]=='>') {
                if(!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else {
                st1.push(s[j]);
            }
        }
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        while(!st2.empty()) {
            cout << st2.top();
            st2.pop();
        }
        cout << '\n';
    }
}