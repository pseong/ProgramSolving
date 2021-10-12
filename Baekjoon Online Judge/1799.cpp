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

int visit[50];
int visit2[50]; // i-j+n
int an[11][11];
int n, ans[2];

void dfs(int i, int j, int cnt, int d) {
    if(j>=n) {
        if(n%2==1) {
            j = j-n;
            i++;
        }
        else {
            if(i%2==0&&d==0 || i%2==1&&d==1) {
                j = 1;
                i++;
            }
            else {
                j = 0;
                i++;
            }
        }
    }
    if(i==n) {
        ans[d] = max(ans[d], cnt);
        return;
    }

    dfs(i, j+2, cnt, d);
    if(an[i][j]!=0 && visit[i+j]==0 && visit2[i-j+n]==0) {
        visit[i+j] = 1;
        visit2[i-j+n] = 1;
        dfs(i, j+2, cnt+1, d);
        visit[i+j] = 0;
        visit2[i-j+n] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> an[i][j];
        }
    }
    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);
    cout << ans[0]+ans[1];
}