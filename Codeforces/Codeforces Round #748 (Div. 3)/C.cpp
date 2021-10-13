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

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int ak[400010]{0};
        for(int i=0; i<k; i++) {
            cin >> ak[i];
            ak[i] = n-ak[i];
        }
        sort(ak, ak+k);

        int cat=n;
        int ans=0;
        for(int i=0; i<k; i++) {
            if(ak[i]<cat) {
                ans++;
                cat -= ak[i];
            }
            else {
                break;
            }
        }
        cout << ans << '\n';
    }
}