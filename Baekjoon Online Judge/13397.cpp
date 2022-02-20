#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m, a[5010];

int calc(int mid) {
    int mx = 0;
    int mn = 10001;
    int section = 1;
    for (int i=0; i<n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if (mx - mn > mid) {
            section++;
            mx = 0;
            mn = 10001;
            i--;
        }
    }
    return section;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int lo = 0;
    int hi = 10000;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cal = calc(mid);
        if (cal <= m) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans;
}