#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=1000000;
ll n, m, a, visitt[N+10], proton[N+10];
vector<int> poss;
vector<int> v[N+10];

pll dfs(int x) {
    if(visitt[x]) return {0, 0};
    visitt[x] = 1;
    pll sum{0, x};
    for(int y : v[x]) {
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
    ll ans=0;
    for(int i=0; i<n; i++) {
        if(!visitt[poss[i]]) {
            pll ret=dfs(poss[i]);
            ans += max(ret.F, ret.S);
        }
    }
    cout << ans;
}