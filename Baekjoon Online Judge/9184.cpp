#include <iostream>

using namespace std;

int dp[200][200][200]{0};
int w(int a, int b, int c) {
    if(a<=0||b<=0||c<=0) {
        dp[0][0][0]=1;
        return 1;
    }
    if(a>20||b>20||c>20) {
        if(dp[20][20][20]) return dp[20][20][20];
        else return w(20, 20, 20);
    }
    if(a<b&&b<c) {
        int d, e, f;
        if(dp[a][b][c-1]) e = dp[a][b][c-1];
        else e = w(a, b, c-1);
        if(dp[a][b-1][c-1]) d = dp[a][b-1][c-1];
        else d= w(a, b-1, c-1);
        if(dp[a][b-1][c]) f = dp[a][b-1][c];
        else f = w(a, b-1, c);
        dp[a][b][c] = d+e-f;
        return dp[a][b][c];
    }
    int d, e, f, g;
    if(dp[a-1][b][c]) d = dp[a-1][b][c];
    else d = w(a-1, b, c);
    if(dp[a-1][b-1][c]) e = dp[a-1][b-1][c];
    else e = w(a-1, b-1, c);
    if(dp[a-1][b][c-1]) f = dp[a-1][b][c-1];
    else f = w(a-1, b, c-1);
    if(dp[a-1][b-1][c-1]) g = dp[a-1][b-1][c-1];
    else g = w(a-1, b-1, c-1);
    dp[a][b][c] = d+e+f-g;
    return dp[a][b][c];
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(true) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==-1&&b==-1&&c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = " << w(a, b, c) << '\n';
    }
}