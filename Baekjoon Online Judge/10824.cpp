#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    string s[4];

    cin >> s[0] >> s[1] >> s[2] >> s[3];

    cout << stoll(s[0]+s[1]) + stoll(s[2]+s[3]);
}