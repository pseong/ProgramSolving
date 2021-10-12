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

int g, p, gi[100010];
int visit[100010]{0};
int dfs(int idx) {
    if(idx>p) return 0;
    int ret=0;
    for(int i=1; i<=gi[idx]; i++) {
        if(visit[i]==0) {
            visit[i] = 1;
            ret = max(ret, 1+dfs(idx+1));
            visit[i] = 0;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> g >> p;
    for(int i=1; i<=p; i++) {
        cin >> gi[i];
    }
    cout << dfs(1);
}