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
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

bool func(pii a, pii b) {
    return a.first > b.first;
}

pii d[300010];
multiset<int> ms;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int m, v;
        cin >> m >> v;
        d[i] = {v, m};
    }
    sort(d, d+n, func);
    for(int i=0; i<k; i++) {
        int c;
        cin >> c;
        ms.insert(c);
    }
    ll ans=0;
    for(int i=0; i<n; i++) {
        int m, v;
        tie(v, m) = d[i];
        auto it=ms.lower_bound(m);
        if(ms.empty()) break;
        if(it==ms.end()) continue;
        else {
            ms.erase(it);
            ans += v;
        }
    }
    cout << ans;
}