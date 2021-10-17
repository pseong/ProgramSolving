#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll n, k, q;
ll depth(ll a) {
    int ret=0;
    while(a!=1) {
        a = (a+k-2)/k;
        ret++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> q;
    for(int i=0; i<q; i++) {
        ll a, b;
        cin >> a >> b;
        if(k==1) {
            cout << abs(a-b) << '\n';
            continue;
        }
        int depth_a=depth(a);
        int depth_b=depth(b);
        if(depth_a<depth_b) {
            swap(a, b);
            swap(depth_a, depth_b);
        }
        int ans=0;
        while(depth_a!=depth_b) {
            a = (a+k-2)/k;
            depth_a--;
            ans++;
        }
        while(a!=b) {
            a = (a+k-2)/k;
            b = (b+k-2)/k;
            ans += 2;
        }
        cout << ans << '\n';
    }
}