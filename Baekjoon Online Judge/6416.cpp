#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<int> vert[100];
int dfs(int node, int par) {
    int ret=1;
    for(int i : vert[node]) {
        if(i==par) continue;
        ret += dfs(i, node);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T=1;
    while(true) {
        map<int, int> u;
        map<int, int> v;
        bool bk=false;
        int cnt=0;
        set<int> node;
        while(true) {
            int a, b;
            cin >> a >> b;
            if(a==-1&&b==-1) {
                bk = true;
                break;
            }
            if(a==0&&b==0) break;
            vert[a].push_back(b);
            u[a]++;
            v[b]++;
            node.insert(a);
            node.insert(b);
            cnt++;
        }
        if(bk) break;
        if(cnt==0) {
            cout << "Case " << T << " is a tree.\n";
            T++;
            for(int i=0; i<100; i++) {
                vert[i].clear();
            }
            continue;
        }
        bool fail=false;
        //if(cnt!=node.size()-1) fail = true;
        for(auto i : v) {
            if(i.second>1) {
                fail = true;
            }
        }
        int root=0;
        int rl_root=0;
        for(auto i : u) {
            if(v[i.first]==0) {
                root++;
                rl_root = i.first;
            }
        }
        if(root!=1) fail = true;

        if(!fail) {
            int ret=dfs(rl_root, 0);
            if(ret!=node.size()) fail = true;
        }

        if(fail) {
            cout << "Case " << T << " is not a tree.\n";
        }
        else cout << "Case " << T << " is a tree.\n";
        for(int i=0; i<100; i++) {
            vert[i].clear();
        }
        T++;
    }
}