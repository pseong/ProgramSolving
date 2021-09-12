#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(1) {
        string s;
        cin >> s;
        if(s == "0") break;
        bool drom = true;
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size()-1-i]) {
                drom = false;
                break;
            }
        }
        cout << (drom ? "yes" : "no") << '\n';
    }
}