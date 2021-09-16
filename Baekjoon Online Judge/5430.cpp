#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        string san;
        cin >> san;
        string trans="";
        deque<int> dq;
        for(int i=1; i<san.size(); i++) {
            if(san[i]==','||san[i]==']') {
                if(!trans.empty()) {
                    int a=stoi(trans);
                    dq.push_back(a);
                    trans="";
                }
            } else {
                trans += san[i];
            }
        }
        bool right=1;
        bool fail=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='R') {
                right ^= 1;
            } else {
                if(dq.empty()) {
                    fail=true;
                    break;
                }
                if(right) {
                    dq.pop_front();

                } else {
                    dq.pop_back();
                }
            }
        }
        if(fail) {
            cout << "error" << '\n';
            continue;
        }
        cout << '[';
        while(!dq.empty()) {
            int a;
            if(right) {
                a = dq.front();
                dq.pop_front();
            } else {
                a = dq.back();
                dq.pop_back();
            }
            cout << a;
            if(!dq.empty()) cout << ",";
        }
        cout << "]\n";
    }
}