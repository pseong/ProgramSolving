#include <iostream>

using namespace std;

int d(int n) {
    int sum=n;
    while(n!=0) {
        sum = sum+n%10;
        n /= 10;
    }
    return sum;
}

int ans[1500000]{0};
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=696933;i++) {
        if(!ans[d(i)]) ans[d(i)] = i;
        else {
            if(ans[d(i)] > i) ans[d(i)] = i;
        }
    }
    cout << ans[n];
}