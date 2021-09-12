#include <iostream>

using namespace std;

bool h(int n) {
    int pre=n%10;
    n /= 10;
    int gap=-9999;
    while(n!=0) {
        int now=n%10;
        if(gap==-9999) {
            gap=now-pre;
        }
        else {
            if(now-pre!=gap) return false;
        }
        pre=now;
        n /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int ans[1010]{0};
    for(int i=1; i<=99; i++) {
        ans[i] = 1;
    }
    for(int i=100; i<=1000; i++) {
        ans[i] = h(i);
    }
    int n;
    cin >> n;
    int anss=0;
    for(int i=1; i<=n; i++) {
        if(ans[i]) anss++;
    }
    cout << anss;
}