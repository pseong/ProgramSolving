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
 
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    return __gcd(a, b);
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int an[50]{0};
        for(int i=0; i<n; i++) {
            cin >> an[i];
        }
 
        int an2[50]{0};
        for(int i=1; i<n; i++) {
            an2[i-1] = an[i]-an[i-1];
        }
 
        int ans=0;
        for(int i=0; i<n-1; i++) {
            ans = gcd(ans, an2[i]);
            //cout << an2[i] << '\n';
        }
        if(ans==0) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}