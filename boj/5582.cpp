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
            }
        }
    }

    int ans=0;;
    for(int i=1; i<=s1.size()-1; i++) {
        for(int j=1; j<=s2.size()-1; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}