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

int depth[100010]{0};
int parent[100010][20]{0};
ll p_cost[100010][20]{0};
vector<pii> v[100010];
void dfs(int node, int d, int pre) {
    depth[node] = d;
    for(auto i : v[node]) {
        if(i.first==pre) continue;
        parent[i.first][0] = node;
        p_cost[i.first][0] = i.second;
        dfs(i.first, d+1, node);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(1, 0, 0);

    for(int k=1; k<=19; k++) {
        for(int i=1; i<=n; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
            p_cost[i][k] = p_cost[i][k-1] + p_cost[parent[i][k-1]][k-1];
        }
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int num;
        cin >> num;
        if(num==1) {
            int a, b;
            cin >> a >> b;

            ll ans=0;
            if(depth[a]<depth[b]) swap(a, b);
            for(int k=19; k>=0; k--) {
                if(depth[a]-depth[b]>=(1<<k)) {
                    ans += p_cost[a][k];
                    a = parent[a][k];
                }
            }

            for(int k=19; k>=0; k--) {
                if(parent[a][k]!=parent[b][k]) {
                    ans += p_cost[a][k];
                    ans += p_cost[b][k];
                    a = parent[a][k];
                    b = parent[b][k];
                }
            }
            if(a!=b) {
                cout << ans+p_cost[a][0]+p_cost[b][0] << '\n';
            }
            else {
                cout << ans << '\n';
            }
        } else if(num==2) {
            int a, b, w;
            cin >> a >> b >> w;

            int ans_a=0;
            int ans_b=0;
            bool sw=false;
            if(depth[a]<depth[b]) {
                sw = true;
                swap(a, b);
            }
            int copy_a = a;
            int copy_b = b;
            for(int k=19; k>=0; k--) {
                if(depth[a]-depth[b]>=(1<<k)) {
                    ans_a += (1<<k);
                    a = parent[a][k];
                }
            }

            for(int k=19; k>=0; k--) {
                if(parent[a][k]!=parent[b][k]) {
                    ans_a += (1<<k);
                    ans_b += (1<<k);
                    a = parent[a][k];
                    b = parent[b][k];
                }
            }
            if(a!=b) {
                ans_a++;
                ans_b++;
            }

            a = copy_a;
            b = copy_b;
            if(sw) {
                swap(a, b);
                swap(ans_a, ans_b);
            }

            if(w<=ans_a+1) {
                w--;
                for(int k=19; k>=0; k--) {
                    if(w>=(1<<k)) {
                        a = parent[a][k];
                        w -= (1<<k);
                    }
                }
                cout << a << '\n';
            } else{
                w -= ans_a;
                w = ans_b-w;
                w++;
                for(int k=19; k>=0; k--) {
                    if(w>=(1<<k)) {
                        b = parent[b][k];
                        w -= (1<<k);
                    }
                }
                cout << b << '\n';
            }
        }
    }
}