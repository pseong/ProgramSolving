#include <bits/stdc++.h>

using namespace std;

int link[1010]{ 0 };
int sizee[1010]{ 0 };

int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if(sizee[a] < sizee[b]) swap(a, b);
    sizee[a] += sizee[b];
    link[b] = a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for(int i = 0; i< m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    for(int i = 1; i <= n; i++) link[i] = i;
    for(int i = 1; i <= n; i++) sizee[i] = 1;

    for(auto p : edges)
        if(!same(p.first, p.second)) unite(p.first, p.second);

    int result = 0;
    for(int i = 1; i <=n; i++)
        if(link[i] == i) result++;

    cout << result;
}