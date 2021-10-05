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

int an[100010][3]{0};
int dpmax[2][3]{0};
int dpmin[2][3]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i][0];
        cin >> an[i][1];
        cin >> an[i][2];
    }

    for(int i=1; i<=n; i++) {
        for(int k=0; k<3; k++) {
            dpmin[1][k] = dpmin[0][k];
            dpmax[1][k] = dpmax[0][k];
            if(k-1>=0) {
                dpmin[1][k] = min(dpmin[1][k], dpmin[0][k-1]);
                dpmax[1][k] = max(dpmax[1][k], dpmax[0][k-1]);
            }
            if(k+1<=2) {
                dpmin[1][k] = min(dpmin[1][k], dpmin[0][k+1]);
                dpmax[1][k] = max(dpmax[1][k], dpmax[0][k+1]);
            }
            dpmin[1][k] += an[i][k];
            dpmax[1][k] += an[i][k];
        }
        dpmin[0][0] = dpmin[1][0];
        dpmin[0][1] = dpmin[1][1];
        dpmin[0][2] = dpmin[1][2];
        dpmax[0][0] = dpmax[1][0];
        dpmax[0][1] = dpmax[1][1];
        dpmax[0][2] = dpmax[1][2];
    }

    cout << max({dpmax[0][0], dpmax[0][1], dpmax[0][2]}) << ' ';
    cout << min({dpmin[0][0], dpmin[0][1], dpmin[0][2]});
}