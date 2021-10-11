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

ll sum[320][320]{0};
int an[320][320]{0};

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> an[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            sum[i][j] = an[i][j];
            sum[i][j] += sum[i-1][j];
            sum[i][j] += sum[i][j-1];
            sum[i][j] -= sum[i-1][j-1];
        }
    }
    ll ans=0;
    for(int x=1; x<=n; x++) {
        for(int y=1; y<=m; y++) {
            for(int i=x; i<=n; i++) {
                bool fail=false;
                for(int j=y; j<=m; j++) {
                    ll res=sum[i][j];
                    res -= sum[i][y-1];
                    res -= sum[x-1][j];
                    res += sum[x-1][y-1];
                    if(res==10) ans++;
                    else if(res>10) fail = true;
                    if(fail) break;
                }
            }
        }
    }
    cout << ans;
}