#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x[200001]{ 0 };
    int n, c;

    cin >> n >> c;
    for(int i = 1; i <= n; ++i) cin >> x[i];

    sort(x + 1, x + 1 + n);

    ll left = 1;
    ll right = x[n] - x[1];

    ll result = 0;
    while(left <= right) {
        ll mid = (left + right) >> 1;
        ll cnt = 0;
        ll pre = -1000000000;

        for(int i = 1; i <= n; i++) {
            if(x[i] - pre >= mid) {
                pre = x[i];
                cnt++;
            }
        }
        if(cnt >= c) {
            result = max(result, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result;
}