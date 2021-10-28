#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=10000*2;
int n, m, id, scc_id=1, d[N+10], sd[N+10], an[N+10];
vector<int> v[N+10];
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
        scc_id++;
    }
    return parent;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, not_a, not_b;
        cin >> a >> b;
        if(a<0) {
            a = (-a)*2+1;
            not_a = a-1;
        }
        else {
            a = a*2;
            not_a = a+1;
        }
        if(b<0) {
            b = (-b)*2+1;
            not_b = b-1;
        }
        else {
            b = b*2;
            not_b = b+1;
        }
        v[not_a].push_back(b);
        v[not_b].push_back(a);
    }

    for(int i=2; i<=n*2+1; i++) {
        if(!d[i]) dfs(i);
    }
    for(int i=2; i<=n*2; i+=2) {
        if(sd[i]==sd[i+1]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1 << '\n';
    vector<pii> order;
    for(int i=2; i<=n*2+1; i++) {
        order.push_back({sd[i], i});
    }
    sort(order.begin(), order.end(), greater<pii>());
    for(int i=1; i<=n; i++) {
        an[i] = -1;
    }
    for(auto at : order) {
        int k=at.S/2;
        if(an[k]==-1) {
            if(at.S%2==1) {
                an[k] = 1;
            }
            else {
                an[k] = 0;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(an[i]==-1) cout << 1 << ' ';
        else cout << an[i] << ' ';
    }
}