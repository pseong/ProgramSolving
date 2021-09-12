#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int r;
        string s;
        cin >> r >> s;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < r; j++) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}