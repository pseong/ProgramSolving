#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
int d[N+10], hit[N+10], SCCId[N+10], SCCIdx, id;
vector<int> vert[100010];
stack<int> st;

int dfs(int x) {
    d[x] = ++id;
    st.push(x);
    int parent=d[x];
    for(int y : vert[x]) {
        if(d[y]==0) parent = min(parent, dfs(y));
        else if(!SCCId[y]) parent = min(parent, d[y]);
    }
    if(parent==d[x]) {
        vector<int> scc;
        while(true) {
            int y=st.top();
            st.pop();
            SCCId[y] = SCCIdx;
            if(y==x) break;
        }
        SCCIdx++;
    }
    return parent;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int v, e;
        cin >> v >> e;
        id = 0;
        SCCIdx = 1;
        for(int i=1; i<=v; i++) {
            SCCId[i] = 0;
            hit[i] = 0;
            d[i] = 0;
            vert[i].clear();
        }

        for(int i=0; i<e; i++) {
            int a, b;
            cin >> a >> b;
            a++; b++;
            vert[a].push_back(b);
        }
        for(int i=1; i<=v; i++) {
            if(d[i]==0) dfs(i);
        }
        for(int i=1; i<=v; i++) {
            for(int j : vert[i]) {
                if(SCCId[i]==SCCId[j]) continue;
                hit[SCCId[j]]++;
            }
        }
        int ans=0;
        int idx=0;
        for(int i=1; i<SCCIdx; i++) {
            if(!hit[i]) {
                ans++;
                idx = i;
            }
        }
        if(ans>1) {
            cout << "Confused\n";
        }
        else {
            for(int i=1; i<=v; i++) {
                if(SCCId[i]==idx) {
                    cout << i-1 << '\n';
                }
            }
        }
        cout << '\n';
    }
}