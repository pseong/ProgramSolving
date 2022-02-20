#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int a[4010], b[4010], c[4010], d[4010];
int n;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
    }

    v.resize(n*n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            v[i*n+j] = c[i]+d[j];
        }
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int sum = a[i] + b[j];

            auto l = lower_bound(v.begin(), v.end(), -sum);

            if (l != v.end() && *l == -sum) {
                auto u = upper_bound(v.begin(), v.end(), -sum);
                ans += u - l;
            }
        }
    }
    
    cout << ans;
}