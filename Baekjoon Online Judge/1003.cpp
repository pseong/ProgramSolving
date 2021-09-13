#include <iostream>
#include <tuple>

using namespace std;
bool visit[50]{0};
int dp0[50]{0};
int dp1[50]{0};

pair<int, int> fibonacci(int n) {
    if (n==0) {
        return {1, 0};
    } else if (n==1) {
        return {0, 1};
    } else {
        int cnt0;
        int cnt1;
        int cnt00;
        int cnt11;
        if(!visit[n-1]) {
            tie(cnt0, cnt1) = fibonacci(n-1);
        }
        if(!visit[n-2]) {
            tie(cnt00, cnt11) = fibonacci(n-2);
        }
        cnt0=dp0[n-1];
        cnt1=dp1[n-1];
        cnt00=dp0[n-2];
        cnt11=dp1[n-2];
        visit[n] = 1;
        dp0[n] = cnt0+cnt00;
        dp1[n] = cnt1+cnt11;
        return {dp0[n], dp1[n]};
    }
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    visit[0] = 1;
    visit[1] = 1;
    dp0[0] = 1;
    dp1[0] = 0;
    dp0[1] = 0;
    dp1[1] = 1;
    while(t--) {
        int n;
        cin >> n;
        auto a=fibonacci(n);
        cout << a.first << ' ' << a.second << '\n';
    }
}