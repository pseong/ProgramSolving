#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=10000;
int k, n, a, b, c, not_a, not_b, not_c, id, d[N*2+10], scc_id=1, sd[N*2+10];
char x, y, z;
vector<int> v[N*2+10];
stack<int> st;

int dfs(int x) {
    d[x] = ++id;
    int parent=d[x];
    st.push(x);
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
        scc_id++;
    }
    return parent;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> k >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> x >> b >> y >> c >> z;
        a *= 2;
        b *= 2;
        c *= 2;
        not_a = a+1;
        not_b = b+1;
        not_c = c+1;
        if(x=='R') swap(a, not_a);
        if(y=='R') swap(b, not_b);
        if(z=='R') swap(c, not_c);
        v[not_a].push_back(b);
        v[not_a].push_back(c);
        v[not_b].push_back(a);
        v[not_b].push_back(c);
        v[not_c].push_back(a);
        v[not_c].push_back(b);
    }

    for(int i=2; i<=k*2+1; i++) {
        if(!d[i]) dfs(i);
    }

    for(int i=2; i<=k*2+1; i+=2) {
        if(sd[i]==sd[i+1]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    vector<pii> order;
    for(int i=2; i<=k*2+1; i++) {
        order.push_back({sd[i], i});
    }
    sort(order.begin(), order.end(), greater<pii>());
    char ans[N+10]{0};
    for(auto at : order) {
        int x=at.S/2;
        if(!ans[x]) {
            if(at.S&1) {
                ans[x] = 'B';
            }
            else {
                ans[x] = 'R';
            }
        }
    }
    for(int i=1; i<=k; i++) {
        cout << ans[i];
    }
}