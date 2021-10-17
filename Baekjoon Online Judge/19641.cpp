#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
int n, s, vi[N+10], idx=1;
vector<int> v[N+10];
pii ans[N+10];
void dfs(int node) {
    vi[node] = 1;
    ans[node].F = idx;
    idx++;
    for(int i : v[node]) {
        if(vi[i]) continue;
        dfs(i);
    }
    ans[node].S = idx;
    idx++;
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        while(true) {
            int b;
            cin >> b;
            if(b==-1) break;
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    for(int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    cin >> s;
    dfs(s);
    for(int i=1; i<=n; i++) {
        cout << i << ' ' << ans[i].F << ' ' << ans[i].S << '\n';
    }
}