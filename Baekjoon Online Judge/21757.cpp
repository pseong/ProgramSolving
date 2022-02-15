#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll arr[100010];
ll prefix_sum[100010];
ll ans[4];
int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    
    if (prefix_sum[n]%4 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    ll sum = prefix_sum[n] / 4;
    ans[0] = 1;
    for (int a=1; a<n; a++) {
        if (prefix_sum[a] == sum*3) {
            ans[3] += ans[2];
        }
        if (prefix_sum[a] == sum*2) {
            ans[2] += ans[1];
        }
        if (prefix_sum[a] == sum) {
            ans[1] += ans[0];
        }
    }
    cout << ans[3];
}