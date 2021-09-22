#include <iostream>

using namespace std;

int dp[31][15001]{0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        for(int j=0; j<=15000; j++) {
            if(dp[i-1][j]) {
                dp[i][j] = dp[i-1][j];
                if(j+a<=15000) {
                    dp[i][j+a] = 1;
                }
                if(abs(j-a)>0 && abs(j-a)<=15000) {
                    dp[i][abs(j-a)] = 1;
                }
            }
        }
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a;
        cin >> a;
        if(a>15000) cout << "N ";
        else cout << ((dp[n][a]) ? 'Y' : 'N') << ' ';
    }
}