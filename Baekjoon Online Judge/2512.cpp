#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, a[10010], m;

int calc(int mx) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += min(a[i], mx);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    int sum = 0;
    int mx = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    cin >> m;

    if (sum <= m) {
        cout << mx;
        return 0;
    }

    int lo = 1;
    int hi = mx;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cal = calc(mid);
        if (cal > m) {
            hi = mid - 1;
        }
        else {
            ans = mid;
            lo = mid + 1;
        }
    }
    cout << ans;
}