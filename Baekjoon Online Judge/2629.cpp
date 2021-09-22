#include <iostream>
#include <vector>

using namespace std;

int dp[50000]{0};
int an[50000]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        vector<int> add;
        for(int j=1; j<=15000; j++) {
            if(dp[j]) {
                if(abs(j-a)>=1 && abs(j-a)<=15000) {
                    add.push_back(abs(j-a));
                }
                if(j+a<=15000) {
                    add.push_back(j+a);
                }
            }
        }
        for(int d : add) dp[d] = 1;
        dp[a] = 1;
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a;
        cin >> a;

        cout << ((dp[a]) ? 'Y' : 'N') << ' ';
    }
}