#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a[1000001]{ 0 };
    int n, m;
    cin >> n >> m;

    ll mx = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    ll left = 1;
    ll right = mx;
    ll result = 0;
    while(left <= right) {
        ll mid = (left + right) >> 1;
        ll sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += max(0ll, a[i] - mid);
        }
        if(sum < m) {
            right = mid - 1;
        } else {
            result = max(result, mid);
            left = mid + 1;
        }
    }
    cout << result;
}