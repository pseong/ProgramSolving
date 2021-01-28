#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string s, s2;
    cin >> s >> s2;
    reverse(s.begin(), s.end());
    reverse(s2.begin(), s2.end());

    int b = stoi(s);
    int b2 = stoi(s2);

    if(b > b2) cout << b;
    else cout << b2;
}