#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int many[200]{ 0 };
    bool what = false;
    int ans = 0;

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        char c = toupper(s[i]);
        many[c]++;
        if(many[ans] == many[c] && ans != c)
            what = true;
        else if(many[ans] < many[c]) {
            ans = c;
            what = false;
        }
        if(ans == c) what = false;
    }
    if(what) cout << '?';
    else cout << (char)ans;
}