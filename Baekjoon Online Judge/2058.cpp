#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=1000000;
ll n, m, a, visitt[N+10], proton[N+10];
vector<int> poss, start;
vector<int> v[N+10];

pll dfs(int x) {
    pll sum{0, x};
    for(int y : v[x]) {
        if(visitt[y]) continue;
        visitt[x] = 1;
        pll ret = dfs(y);
        sum.F += max(ret.S, ret.F);
        sum.S += ret.F;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a;
        poss.push_back(a);
    }
    for(int i=0; i<m; i++) {
        cin >> a;
        proton[a] = 1;
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(proton[abs(poss[i]-poss[j])]) {
                v[poss[i]].push_back(poss[j]);
                v[poss[j]].push_back(poss[i]);
            }
        }
    }
    for(int i=0; i<poss.size(); i++) {
        if(proton[poss[i]]) {
            v[0].push_back(poss[i]);
            v[poss[i]].push_back(0);
        }
    }

    visitt[0] = 1;
    pll ans=dfs(0);
    cout << ans.F;
}