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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    vector<pii> v[600];
    while(tc--) {
        int n, m, w;
        cin >> n >> m >> w;
        for(int i=0; i<m; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            v[s].push_back({e, t});
            v[e].push_back({s, t}); 
        }
        for(int i=0; i<w; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            v[s].push_back({e, -t});
        }

        int an[600]{0};
        for(int i=1; i<=n; i++) {
            an[i] = 1000000000;
        }
        bool ans=false;
        for(int i=0; i<n; i++) {
            for(int j=1; j<=n; j++) {
                for(auto aut : v[j]) {
                    int a, b;
                    tie(a, b) = aut;
                    if(an[a]>an[j]+b) {
                        if(i==n-1) { 
                            ans = true;
                        }
                        an[a] = an[j]+b;
                    }
                }
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}