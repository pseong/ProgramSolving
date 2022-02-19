#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m;
vector<int> ns;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        ns.push_back(a);
    }
    sort(ns.begin(), ns.end());

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        int idx1 = lower_bound(ns.begin(), ns.end(), a) - ns.begin();
        int idx2 = upper_bound(ns.begin(), ns.end(), b) - ns.begin();
        cout << idx2 - idx1 << '\n';
    }
}