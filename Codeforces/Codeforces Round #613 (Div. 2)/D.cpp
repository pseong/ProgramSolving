#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int dfs(vector<int> a, int b) {
    if(b==0) {
        bool same=1;
        for(int i=0; i+1<a.size(); i++) {
            if(a[i]!=a[i+1]) same = 0;
        }
        return !same;
    }
    vector<int> c[2];
    for(int i=0; i<a.size(); i++) {
        c[a[i]>>b&1].push_back(a[i]);
    }
    if(c[0].empty()) {
        return dfs(c[1], b-1);
    }
    if(c[1].empty()) {
        return dfs(c[0], b-1);
    }
    int d1=dfs(c[0], b-1);
    int d2=dfs(c[1], b-1);
    return 1<<b|min(d1, d2);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int b;
        cin >> b;
        a.push_back(b);
    }
    cout << dfs(a, 29);
}