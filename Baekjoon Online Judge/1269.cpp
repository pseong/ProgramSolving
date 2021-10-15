#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<int> result(500000);
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int an[200010]{0};
    int bm[200010]{0};
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    sort(an, an+n);
    for (int i=0; i<m; i++) {
        cin >> bm[i];
    }
    sort(bm, bm+m);
    auto it=set_symmetric_difference(an, an+n, bm, bm+m, result.begin());
    result.resize(it-result.begin());
    cout << result.size();
}