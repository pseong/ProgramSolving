#include <iostream>

using namespace std;

int dp[20]{0};

int factorial(int n) {
    if(n==0) return 1;
    if(dp[n-1]) return n*dp[n-1];
    else return n*factorial(n-1); 
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    dp[0] = 1;
    dp[1] = 1;
    cout << factorial(n)/factorial(k)/factorial(n-k);
}