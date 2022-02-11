#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int arr[100010];
int prefix_sum[100010];
int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    int ans = 0;
    for (int i=2; i<n; i++) {
        int cal = prefix_sum[n] - prefix_sum[i] + 
            prefix_sum[n] - prefix_sum[1] - arr[i];
        ans = max(ans, cal);
    }
    for (int i=2; i<n; i++) {
        int cal = prefix_sum[i-1] + prefix_sum[n] - 
            arr[n] - arr[i];
        ans = max(ans, cal);
    }
    for (int i=2; i<n; i++) {
        int cal = prefix_sum[i] - prefix_sum[1] + 
            prefix_sum[n-1] - prefix_sum[i-1];
        ans = max(ans, cal);
    }
    cout << ans;
}