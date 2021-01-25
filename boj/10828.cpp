#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    stack<int> s;
    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "push") {
            int a;
            cin >> a;
            s.push(a);
        } else if(cmd == "pop") {
            if(s.size() > 0) {
                cout << s.top() << '\n';
                s.pop(); // 있을경우만
            } else cout << -1 << '\n';
        } else if(cmd == "size") {
            cout << s.size() << '\n';
        } else if(cmd == "empty") {
            cout << s.empty() << '\n';
        } else if(cmd == "top") {
            if(s.size()) cout << s.top() << '\n';
            else cout << -1 << '\n';
        }
    }
}