#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <cstring>

using namespace std;

vector<pair<int, int>> vert[1010];
int trace[1010]{0};
unsigned int ans[1010]{0};
int s, e;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vert[a].push_back({b, c});
    }

    cin >> s >> e;
    memset(ans, -1, sizeof(ans));
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    trace[s] = s;
    ans[s] = 0;
    while(!pq.empty()) {
        int w, v;
        tie(w, v) = pq.top();
        w = -w;
        pq.pop();
        if(ans[v] < w) continue;
        for(auto a : vert[v]) {
            int w2, v2;
            tie(v2, w2) = a;
            if(ans[v2] <= w+w2) continue;
            ans[v2] = w+w2;
            trace[v2] = v;
            pq.push({-(w+w2), v2});
        }
    }

    cout << ans[e] << '\n';
    int go=e;
    stack<int> st;
    while(go!=s) {
        st.push(go);
        go = trace[go];
    }
    st.push(s);
    cout << st.size() << '\n';
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}