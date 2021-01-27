#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    string s;
    getline(cin, s);

    int cnt = 0;
    bool word = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') word = true;
        else if(s[i] == ' ' && word == true) {
            word = false;
            cnt++;
        }
    }
    if(word) cnt++;
    cout << cnt;
}