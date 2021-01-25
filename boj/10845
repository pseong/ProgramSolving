#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    queue<int> que;
    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "push") {
            int a;
            cin >> a;
            que.push(a);
        } else if(cmd == "pop") {
            if(que.size() > 0) {
                cout << que.front() << '\n';
                que.pop(); // 있을경우만
            } else cout << -1 << '\n';
        } else if(cmd == "size") {
            cout << que.size() << '\n';
        } else if(cmd == "empty") {
            cout << que.empty() << '\n';
        } else if(cmd == "front") {
            if(que.size()) cout << que.front() << '\n';
            else cout << -1 << '\n';
        } else if(cmd == "back") {
            if(que.size()) cout << que.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}