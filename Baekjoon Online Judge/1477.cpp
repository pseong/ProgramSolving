#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m, l;
vector<int> v;
vector<int> v2;

int calc(int mid) {
    int rest = m;
    for (int i=0; i<v2.size(); i++) {
        if (v2[i] > mid) {
            int use = (v2[i]+mid-1) / mid - 1;
            if (rest >= use) {
                rest -= use;
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> l;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    if (n != 0) {
        v2.push_back(v[0]);
        for (int i=1; i<n; i++) {
            v2.push_back(v[i]-v[i-1]);
        }
        v2.push_back(l-v[n-1]);
    }
    else {
        v2.push_back(l);
    }

    int lo = 1;
    int hi = 1000;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cal = calc(mid);
        if (cal == 1) {
            ans = mid;
            hi = mid - 1;
        }
        else if (cal == 0) {
            lo = mid + 1;
        }
    }
    cout << ans;
}