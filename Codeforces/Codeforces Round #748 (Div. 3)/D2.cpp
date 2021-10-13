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
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll an[50]{0};
        map<ll, ll> mp;
        for(ll i=0; i<n; i++) {
            cin >> an[i];
            mp[an[i]]++;
        }
 
        bool bk=false;
        for(auto a : mp) {
            if(a.second>=n/2) {
                cout << -1 << '\n';
                bk = true;
                break;
            }
        }
        if(bk) continue;
 
        ll ans=1;
        map<ll, ll> see[40];
        ll same[40]{0};
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                ll go=abs(an[i]-an[j]);
                
                if(go!=0) {
                    for(ll m=1; m*m<=go; m++) {
                        if (m*m==go) {
                            see[i][m]++;
                        }
                        else if (go%m==0) {
                            see[i][m]++;
                            see[i][go/m]++;
                        }
                    }
                }
                else same[i]++;
            }
        }
 
        for(ll i=0; i<n; i++) {
            ll res=0;
            for(auto a : see[i]) {
                if(a.second+same[i]>=n/2) {
                    res = max(res, a.first);
                }
            }
            ans = max(ans, res);
        }
        cout << ans << '\n';
    }
}