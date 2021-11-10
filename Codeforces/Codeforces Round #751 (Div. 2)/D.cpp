#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
 
const int N=300000;
int n, an[N+10], bn[N+10], visit[N+10], visit2[N+10], trace[N+10];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> bn[i];
    }
        
    deque<pii> bfs;
    bfs.push_back({n, n});
    visit[n] = 1;
    trace[n] = n;
    int finish=false;
    while(!bfs.empty() && !finish) {
        int d_x, x;
        tie (d_x, x) = bfs.front();
        bfs.pop_front();
        for(int i=0; i<=an[d_x]; i++) {
            if(visit2[d_x]) break;
            int jmp=d_x-i;
            if(jmp<=0) {
                trace[0] = x;
                finish = true;
                break;
            }
            int d_jmp = min(jmp + bn[jmp], n);
            if(visit[d_jmp]) continue;
            visit[d_jmp] = true;
            trace[jmp] = x;
            bfs.push_back({d_jmp, jmp});
        }
        visit2[d_x] = 1;
    }
    if(trace[0]==0) {
        cout << -1;
        return 0;
    }
    int go=0;
    stack<int> st;
    while(go!=n) {
        st.push(go);
        go = trace[go];
    }
    cout << st.size() << '\n';
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}