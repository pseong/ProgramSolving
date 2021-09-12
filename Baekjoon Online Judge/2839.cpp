#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n%3!=0 && (n-5<0 || (n-5)%3!=0) && (n-10<0 || (n-10)%3!=0)) {
        cout << -1;
        return 0;
    }
    int ans=0;
    while(n>=0&&n%5!=0) {
        ans += 1;
        n -= 3;
    }
    ans+=n/5;
    cout << ans;
}