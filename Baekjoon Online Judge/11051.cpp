#include <iostream>

using namespace std;

int dp[1020][1020]{0};

int f(int n, int k) {
    if(n==0) return 1;
    if(n==k) return 1;
    if(k==0) return 1;
    if(dp[n][k]) return dp[n][k];
    dp[n][k] = f(n-1, k-1) + f(n-1, k);
    return dp[n][k] % 10007;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    cout << f(n, k) % 10007;
}