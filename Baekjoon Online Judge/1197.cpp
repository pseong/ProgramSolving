#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int parent[10010]{0};

int getParent(int i) {
    if(parent[i]==i) return i;
    return parent[i] = getParent(parent[i]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a<b) {
        parent[b] = a;
    } else if(a>b) {
        parent[a] = b;
    }
}

int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int v, e;
    cin >> v >> e;
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    for(int i=0; i<=v; i++) {
        parent[i] = i;
    }
    int cnt=0;
    long long ans=0;
    sort(edges.begin(), edges.end());
    for(int i=0; i<edges.size(); i++) {
        if(cnt==v-1) break;
        int a, b, c;
        tie(c, a, b) = edges[i];
        if(findParent(a, b)) continue;
        cnt++;
        ans += c;
        unionParent(a, b);
    }
    cout << ans;
}