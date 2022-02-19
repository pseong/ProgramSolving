#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int x, y;

int calc(int cnt) {
    return (int)((long double)(x+cnt) / (y+cnt) * 100);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> y >> x;
    int per = (int)((long double)x / y * 100);
    if (per >= 99) {
        cout << -1;
        return 0;
    }
    int lo = 1;
    int hi = 1000000000;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cal = calc(mid);
        if (cal <= per) {
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid - 1;
        }
    }
    cout << ans;
}