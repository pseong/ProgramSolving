#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <list>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int t, n, m, an[1010], bm[1010];
vector<int> a;
vector<int> b;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> t;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        an[i] = an[i-1] + x;
    }

    cin >> m;
    for(int i=1; i<=m; i++) {
        int x;
        cin >> x;
        bm[i] = bm[i-1] + x;
    }

    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            int sum=an[j]-an[i-1];
            a.push_back(sum);
        }
    }
    for(int i=1; i<=m; i++) {
        for(int j=i; j<=m; j++) {
            int sum=bm[j]-bm[i-1];
            b.push_back(sum);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans=0;
    for(int i=0; i<a.size();) {
        int one=a[i];
        ll cnt1 = upper_bound(a.begin(), a.end(), one)-lower_bound(a.begin(), a.end(), one);
        i += cnt1;
        ll cnt2 = upper_bound(b.begin(), b.end(), t-one)-lower_bound(b.begin(), b.end(), t-one);
        ans += cnt1*cnt2;
    }
    cout << ans;
}