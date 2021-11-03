#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
const int N=1000;
int n, m, id, d[N*2+10], scc_id=1, sd[N*2+10];
vector<int> v[N*2+10];
stack<int> st;

int dfs(int x) {
    d[x] = ++id;
    st.push(x);
    int parent = d[x];
    for(int y : v[x]) {
        if(!d[y]) parent = min(parent, dfs(y));
        else if(!sd[y]) parent = min(parent, d[y]);
    }
    if(parent==d[x]) {
        while(true) {
            int y=st.top();
            st.pop();
            sd[y] = scc_id;
            if(x==y) break;
        }
        ++scc_id;
    }
    return parent;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(cin >> n >> m) {
        for(int i=0; i<N*2+9; i++) {
            v[i].clear();
            d[i] = 0;
            sd[i] = 0;
        }
        id = 0;
        scc_id = 1;
        for(int i=0; i<m; i++) {
            char x, y;
            int a, b, not_a, not_b;
            cin >> x >> a >> y >> b;
            a *= 2;
            b *= 2;
            not_a = a+1;
            not_b = b+1;
            if(x=='-') swap(a, not_a);
            if(y=='-') swap(b, not_b);
            v[not_b].push_back(a);
            v[not_a].push_back(b);
        }
        for(int i=2; i<=n*2+1; i++) {
            if(!d[i]) dfs(i);
        }
        bool fail=false;
        for(int i=2; i<=n*2+1; i+=2) {
            if(sd[i]==sd[i+1]) {
                fail = true;
                break;
            }
        }
        if(fail) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}