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
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }

    int s, e;
    cin >> s >> e;
    priority_queue<pii> pq;
    int dist[1010]{0};
    memset(dist, -1, sizeof(dist));
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        int c, w;
        tie(w, c) = pq.top();
        pq.pop();
        w = -w;
        if(dist[c] < w) continue;
        for(auto aut : v[c]) {
            int c2, w2;
            tie(c2, w2) = aut;
            if(dist[c2]==-1||dist[c2]>w+w2) {
                dist[c2] = w+w2;
                pq.push({-(w+w2), c2});
            }
        }
    }
    
    cout << dist[e];
}