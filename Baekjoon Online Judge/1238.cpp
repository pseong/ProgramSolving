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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    vector<pii> v[1010];
    int n, m, x;
    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    int ans[1010]{0};
    for(int i=1; i<=n; i++) {
        priority_queue<pii> bfs;
        bfs.push({0, i});
        int dist[1010]{0};
        memset(dist, -1, sizeof(dist));
        dist[i] = 0;
        while(!bfs.empty()) {
            int w, c;
            tie(w, c) = bfs.top();
            bfs.pop();
            w = -w;
            if(dist[c] < w) continue;
            for(auto aut : v[c]) {
                int w2, c2;
                tie(c2, w2) = aut;
                if(dist[c2]==-1||dist[c2]>w+w2) {
                    dist[c2] = w+w2;
                    bfs.push({-(w+w2), c2});
                }
            }
        }
        ans[i] += dist[x];
        if(i==x) {
            for(int k=1; k<=n; k++) {
                ans[k] += dist[k];
            }
        }
    }
    int ans_mx=0;
    for(int i=1; i<=n; i++) {
        if(ans[i]>ans_mx) {
            ans_mx = ans[i];
        }
    }
    cout << ans_mx;
}