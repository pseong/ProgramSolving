#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int v[40404];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    for (int i=1; i<=40000; i++) {
        sum += 2*(i-(i-1)/3)-2;
        v[i] = sum;
    }
    
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        
        int lo = 1;
        int hi = 40000;
        int ans = 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (v[mid] >= n) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}