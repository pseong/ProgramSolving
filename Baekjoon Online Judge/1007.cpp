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
        int n;
        cin >> n;
        pii an[20];
        for(int i=0; i<n; i++) {
            cin >> an[i].first;
            cin >> an[i].second;
        }
        vector<int> v;
        for(int i=0; i<n/2; i++)
            v.push_back(0);
        for(int i=0; i<n/2; i++)
            v.push_back(1);
        double ans=5000000;
        do {
            pair<double, double> res={0, 0};
            for(int i=0; i<n; i++) {
                if(v[i]) {
                    res.first += an[i].first;
                    res.second += an[i].second;
                }
                else {
                    res.first -= an[i].first;
                    res.second -= an[i].second;
                }
            }
            ans = min(ans, sqrt(res.first*res.first+res.second*res.second));
        } while(next_permutation(v.begin(), v.end()));
        cout << fixed << setprecision(10) << ans << '\n';
    }
}