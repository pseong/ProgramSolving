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

bool a[1<<26];
char an[25][25];
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};
int r, c, ans;

void dfs(int a, int b, int v, int w) {
    ans = max(ans, w);
    for(int d=0; d<4; d++) {
        int x=a+dx[d];
        int y=b+dy[d];
        if(x<0||x>=r||y<0||y>=c) continue;
        if(v&(1<<(an[x][y]-'A'))) continue;
        dfs(x, y, (v|(1<<(an[x][y]-'A'))), w+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> an[i][j];
        }
    }
    dfs(0, 0, 1<<(an[0][0]-'A'), 1);
    cout << ans;
}