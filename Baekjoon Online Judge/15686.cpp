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
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

vector<pii> chi;
vector<pii> hom;
int n, m;
int an[60][60]{0};
int ans=1000000000;
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};

int cal(int visit) {
    int ret=0;
    for(int i=0; i<hom.size(); i++) {
        int u, v;
        tie(u, v) = hom[i];
        int dist=1000000000;
        for(int j=0; j<chi.size(); j++) {
            if(visit&(1<<j)) {
                dist = min(dist, abs(u-chi[j].first)+abs(v-chi[j].second));
            }
        }
        ret += dist;
    }
    return ret;
}

void go(int idx, int visit, int cnt) {
    if(cnt==m) {
        ans = min(ans, cal(visit));
        return;
    }
    if(idx==chi.size()) return;
    go(idx+1, visit, cnt);
    go(idx+1, visit|(1<<idx), cnt+1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
            if(an[i][j]==2) chi.push_back({i, j});
            else if(an[i][j]==1) hom.push_back({i, j});
        }
    }
    go(0, 0, 0);
    cout << ans;
}