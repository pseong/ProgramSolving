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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    queue<pii> bfs;
    bfs.push({n, 0});
    int dp[100010]{0};
    int cnt[100010]{0};
    cnt[n] = 1;
    while(!bfs.empty()) {
        int v, w;
        tie(v, w) = bfs.front();
        bfs.pop();
        if(v-1>=0) {
            if(cnt[v-1]) {
                if(dp[v-1]==w+1) {
                    cnt[v-1] += cnt[v];
                }
            } else {
                dp[v-1] = w+1;
                bfs.push({v-1, w+1});
                cnt[v-1] += cnt[v];
            }
        }
        if(v+1<=100000) {
            if(cnt[v+1]) {
                if(dp[v+1]==w+1) {
                    cnt[v+1] += cnt[v];
                }
            } else {
                dp[v+1] = w+1;
                bfs.push({v+1, w+1});
                cnt[v+1] += cnt[v];
            }
        }
        if(v*2<=100000) {
            if(cnt[v*2]) {
                if(dp[v*2]==w+1) {
                    cnt[v*2] += cnt[v];
                }
            } else {
                dp[v*2] = w+1;
                bfs.push({v*2, w+1});
                cnt[v*2] += cnt[v];
            }
        }
    }
    cout << dp[k] << '\n' << cnt[k];
}