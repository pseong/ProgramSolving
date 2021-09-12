#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    deque<int> dque;
    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "push_front") {
            int a;
            cin >> a;
            dque.push_front(a);
        } else if(cmd == "push_back") {
            int a;
            cin >> a;
            dque.push_back(a);
        } else if(cmd == "pop_front") {
            if(dque.size() > 0) {
                cout << dque.front() << '\n';
                dque.pop_front();
            } else cout << -1 << '\n';
        } else if(cmd == "pop_back") {
            if(dque.size() > 0) {
                cout << dque.back() << '\n';
                dque.pop_back();
            } else cout << -1 << '\n';
        } else if(cmd == "size") {
            cout << dque.size() << '\n';
        } else if(cmd == "empty") {
            cout << dque.empty() << '\n';
        } else if(cmd == "front") {
            if(dque.size()) cout << dque.front() << '\n';
            else cout << -1 << '\n';
        } else if(cmd == "back") {
            if(dque.size()) cout << dque.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}