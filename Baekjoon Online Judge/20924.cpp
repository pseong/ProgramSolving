#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, r;
vector<pii> v[200010];
int ans1=-1;
int ans2=-1;
int ans3=-1;

void dfs2(int node, int par, int dist) {
    for(auto a : v[node]) {
        if(a.first==par) continue;
        ans2 = max(ans2, dist+a.second);
        dfs2(a.first, node, dist+a.second);
    }
}

void dfs(int node, int par, int dist) {
    int cnt=0;
    for(auto a : v[node]) {
        if(a.first==par) continue;
        cnt++;
    }
    if(cnt>1 && ans1==-1) {
        ans1 = dist;
        dfs2(node, par, 0);
    }
    else {
        for(auto a : v[node]) {
            if(a.first==par) continue;
            ans3 = max(ans3, dist+a.second);
            dfs(a.first, node, dist+a.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> r;
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(r, 0, 0);
    if(ans1==-1) ans1 = ans3;
    cout << max(ans1, 0) << ' ' << max(ans2, 0);
}