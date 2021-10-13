
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
 
set<ll> v[400010];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        for(ll i=0; i<n-1; i++) {
            ll a, b;
            cin >> a >> b;
            v[a].insert(b);
            v[b].insert(a);
        }
 
        vector<ll> leaf;
        for(ll i=1; i<=n; i++) {
            if(v[i].size()==1) {
                leaf.push_back(i);
            }
        }
 
        ll ans=n;
        vector<ll> leaf2;
        for(ll i=0; i<k; i++) {
            if(ans<=2) ans = 0;
            else {
                for(ll c : leaf) {
                    ans--;
                    ll opp=*v[c].begin();
                    v[opp].erase(c);
                    if(v[opp].size()==1) leaf2.push_back(opp);
                }
                leaf = leaf2;
                leaf2.clear();
            }
        }
        cout << ans << '\n';
 
        for(int i=1; i<=n; i++) {
            v[i].clear();
        }
    }
}