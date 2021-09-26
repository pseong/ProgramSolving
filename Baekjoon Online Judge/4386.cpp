#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <iomanip>

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
    
    int n;
    cin >> n;
    pair<double, double> an[110];
    for(int i=1; i<=n; i++) {
        double a, b;
        cin >> a >> b;
        an[i] = {a, b};
    }
    vector<tuple<double, int, int>> edges;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            double dist=sqrt((an[i].first-an[j].first)*(an[i].first-an[j].first)
                                +(an[i].second-an[j].second)*(an[i].second-an[j].second));
            edges.push_back({dist, i, j});
        }
    }
    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }
    int cnt=0;
    double ans=0;
    sort(edges.begin(), edges.end());
    for(int i=0; i<edges.size(); i++) {
        if(cnt==n-1) break;
        double a, b, c;
        tie(c, a, b) = edges[i];
        if(findParent(a, b)) continue;
        cnt++;
        ans += c;
        unionParent(a, b);
    }
    cout << fixed << setprecision(2) << ans;
}