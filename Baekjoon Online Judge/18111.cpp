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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int h=0;
    int n, m, b;
    int an[600][600]{0};
    cin >> n >> m >> b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> an[i][j];
            h = max(h, an[i][j]);
        }
    }

    int ans=1000000000;
    int ans2=-1;
    for(int k=h; k>=0; k--) {
        int left=b;
        int time=0;
        int fail=false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(an[i][j] > k) {
                    left += an[i][j]-k;
                    time += (an[i][j]-k)*2;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(an[i][j] < k) {
                    left -= k-an[i][j];
                    if(left < 0) {
                        fail = true;
                        break;
                    }
                    time += (k-an[i][j]);
                }
            }
        }
        if(!fail) {
            if(ans > time) {
                ans = time;
                ans2 = k;
            }
        }
    }
    cout << ans << ' ' << ans2;
}