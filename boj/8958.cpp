#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        int score = 0;
        int plus = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'O') {
                score += plus;
                plus++;
            } else plus = 1;
        }
        cout << score << '\n';
    }
}