#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    list<char> vc;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i ++)
        vc.push_back(s[i]);

    auto it = vc.end();
    int m;
    cin >> m;
    while(m--) {
        char cmd;
        cin >> cmd;
        switch(cmd) {
            case 'L':
                if(it != vc.begin()) it--;
                break;
            case 'D':
                if(it != vc.end()) it++;
                break;
            case 'B':
                if(it != vc.begin()) it = vc.erase(--it);
                break;
            case 'P':
                char a;
                cin >> a;
                vc.insert(it, a);
                break;
        }
    }
    for(char c : vc)
        cout << c;
}