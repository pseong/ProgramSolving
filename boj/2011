#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    string s;
    cin >> s;

    if(stoi(s.substr(0, 1)) == 0) {
        cout << 0;
        return 0;
    }

    int dp[5010]{ 0 };
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2 - 1; i < s.size(); i++) {
        int e = stoi(s.substr(i - 1, 2));

        if(e == 0) break;
        if(e >= 1 && e < 10) {
            int d = 0;
            if(i > 1) stoi(s.substr(i - 2, 1));
            if(d > 2) break;
            dp[i + 1] = (dp[i + 1] + dp[i]) % 1000000;
        } else if (e >= 10 && e < 27) {
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % 1000000;
            if(e % 10 != 0) dp[i + 1] = (dp[i + 1] + dp[i]) % 1000000;
        } else {
            if(e % 10 == 0) break;
            dp[i + 1] = (dp[i + 1] + dp[i]) % 1000000;
        }
    }
    cout << dp[s.size()];
}