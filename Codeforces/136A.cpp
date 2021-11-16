#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int ans[110]{0};
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        ans[a] = i;
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
}