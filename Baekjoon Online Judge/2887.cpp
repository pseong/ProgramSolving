#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int parent[100010]{0};

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
    
    int n;
    cin >> n;
    vector<pair<int, int>> an_x;
    vector<pair<int, int>> an_y;
    vector<pair<int, int>> an_z;
    for(int i=0; i<n; i++) {
        parent[i] = i;
        int a, b, c;
        cin >> a >> b >> c;
        an_x.push_back({a, i});
        an_y.push_back({b, i});
        an_z.push_back({c, i});
    }
    sort(an_x.begin(), an_x.end());
    sort(an_y.begin(), an_y.end());
    sort(an_z.begin(), an_z.end());
    vector<tuple<int, int, int>> edges;
    for(int i=1; i<an_x.size(); i++) {
        edges.push_back({abs(an_x[i-1].first - an_x[i].first), an_x[i].second, an_x[i-1].second});
        edges.push_back({abs(an_y[i-1].first - an_y[i].first), an_y[i].second, an_y[i-1].second});
        edges.push_back({abs(an_z[i-1].first - an_z[i].first), an_z[i].second, an_z[i-1].second});
    }
    sort(edges.begin(), edges.end());
    int cnt=0;
    long long ans=0;
    for(int i=0; i<edges.size(); i++) {
        if(cnt==n-1) break;
        int a, b, c;
        tie(c, a, b) = edges[i];
        if(findParent(a, b)) continue;
        cnt++;
        ans += c;
        unionParent(a, b);
    }
    cout << ans;
}