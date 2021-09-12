#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int t[25]{0};
int p[25]{0};
int ans=0;

void func(int now, int money) {
    if(now == n+1) {
        if(ans<money) ans = money;
        return;
    }
    if(now > n+1) {
        return;
    }
    func(now+t[now], money+p[now]);
    func(now+1, money);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;

    for(int i=1; i<=24; i++) {
        t[i] = 100;
    }

    for(int i=1; i<=n; i++) {
        cin >> t[i];
        cin >> p[i];
    }
    
    func(1, 0);
    cout << ans;
}