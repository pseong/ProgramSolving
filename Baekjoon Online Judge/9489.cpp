#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

vector<int> v[1010];
int n, k, an[1010];
int parent[1010];
int link[1000010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(true) {
        cin >> n >> k;
        if(n==0&&k==0) break;
        for(int i=0; i<n; i++) {
            cin >> an[i];
            link[an[i]] = i+1;
        }

        queue<int> q;
        q.push(link[an[0]]);
        int idx=1;
        while(!q.empty()) {
            if(idx==n) break;
            int a=q.front();
            q.pop();
            v[a].push_back(link[an[idx]]);
            v[link[an[idx]]].push_back(a);
            q.push(link[an[idx]]);
            parent[link[an[idx]]] = a;
            while(idx<n-1 && an[idx]+1==an[idx+1]) {
                idx++;
                v[a].push_back(link[an[idx]]);
                v[link[an[idx]]].push_back(a);
                q.push(link[an[idx]]);
                parent[link[an[idx]]] = a;
            }
            idx++;
        }

        int p=parent[parent[link[k]]];
        if(p==0) cout << 0 << '\n';
        else {
            int cnt=0;
            for(int i : v[p]) {
                if(i==parent[p]) continue;
                if(i==parent[link[k]]) continue;
                int res=0;
                for(int j : v[i]) {
                    if(j==p) continue;
                    res++;
                }
                cnt += res;
            }
            cout << cnt << '\n';
        }
        memset(parent, 0, sizeof(parent));
        for(int i=0; i<=1008; i++) {
            v[i].clear();
        }
    }
}