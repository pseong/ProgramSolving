#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000010]{0};
int back[1000010]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    dp[1]=0; back[1] = 0;
    dp[2]=1; back[2] = 1;
    dp[3]=1; back[3] = 1;
    for(int i=4; i<=n; i++) {
        dp[i] = dp[i-1]+1;
        back[i] = i-1;
        if(i%2==0 && dp[i]>dp[i/2]+1) {
            dp[i] = dp[i/2]+1;
            back[i] = i/2;
        }
        if(i%3==0 && dp[i]>dp[i/3]+1) {
            dp[i] = dp[i/3]+1;
            back[i] = i/3;
        }
    }
    cout << dp[n] << '\n';

    while(n>0) {
        cout << n << ' ';
        n=back[n];
    }
}