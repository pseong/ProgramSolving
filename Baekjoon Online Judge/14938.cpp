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

    int n, m, r;
    cin >> n >> m >> r;
    int an[110]{0};
    vector<pii> v[110];
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for(int i=0; i<r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        int dist[110]{0};
        memset(dist, -1, sizeof(dist));
        priority_queue<pii> pq;
        pq.push({0, i});
        dist[i] = 0;
        int res=0;
        while(!pq.empty()) {
            int w, c;
            tie(w, c) = pq.top();
            pq.pop();
            w = -w;
            if(dist[c]<w || dist[c]>m) continue;
            res += an[c];
            for(auto a : v[c]) {
                int c2, w2;
                tie(c2, w2) = a;
                if(dist[c2]==-1 || dist[c2]>w+w2) {
                    dist[c2] = w+w2;
                    pq.push({-(w+w2), c2});
                }
            }
        }
        ans = max(ans, res);
    }
    cout << ans;
}