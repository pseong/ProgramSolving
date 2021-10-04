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

int an[1500][1500]{0};
int sum[1500][1500]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+an[i][j];
        }
    }
    for(int i=0; i<m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans=sum[x2][y2];
        ans -= sum[x2][y1-1];
        ans -= sum[x1-1][y2];
        ans += sum[x1-1][y1-1];
        cout << ans << '\n';
    }
}