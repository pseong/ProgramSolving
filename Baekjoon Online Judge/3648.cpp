#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=1000*2;
int n, m, a, b, not_a, not_b, id, d[N+10], scc_id=1, sd[N+10], ans[N/2+5];
vector<int> v[N+10];
vector<pii> order;
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

    while(cin >> n >> m) {
        memset(d, 0, sizeof(d));
        memset(sd, 0, sizeof(sd));
        id=0; scc_id=1;
        order.clear();
        for(int i=1; i<n*2+5; i++) {
            v[i].clear();
        }
        for(int i=0; i<m; i++) {
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
        bool bk=false;
        for(int i=2; i<=n*2+1; i+=2) {
            if(sd[i]==sd[i+1]) {
                cout << "no\n";
                bk = true;
                break;
            }
        }
        if(bk) continue;
        for(int i=2; i<=n*2+1; i++) {
            order.push_back({sd[i], i});
        }
        sort(order.begin(), order.end(), greater<pii>());
        memset(ans, -1, sizeof(ans));
        for(auto at : order) {
            int x=at.S/2;
            if(ans[x]!=-1) {
                if(at.F%2==0) {
                    ans[x] = 0;
                }
                else {
                    ans[x] = 1;
                }
            }
        }
        if(ans[1]) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}