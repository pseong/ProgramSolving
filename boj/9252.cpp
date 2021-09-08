#include <iostream>
#include <string>
#include <stack>

using namespace std;
int dp[1001][1001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin >> s2 >> s1;
    s1 = " " + s1;
    s2 = " " + s2;

    for(int i=1; i<=s1.size()-1; i++) {
        for(int j=1; j<=s2.size()-1; j++) {
            if(s1[i]==s2[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int ans=dp[s1.size()-1][s2.size()-1];
    int x=s1.size()-1;
    int y=s2.size()-1;
    stack<char> ans2;
    for(int i=0; i<ans; i++) {
        while(dp[x][y]==dp[x][y-1]) {
            y--;
        }
        while(dp[x][y]==dp[x-1][y]) {
            x--;
        }
        ans2.push(s1[x]);
        x--;
        y--;
    }

    cout << ans << '\n';
    while(!ans2.empty()) {
        cout << ans2.top();
        ans2.pop();
    }
}