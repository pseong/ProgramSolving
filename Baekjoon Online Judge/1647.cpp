#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <list>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

vector<tiii> v;
vector<tiii> edges;

int parent[100010]{0};

int getParent(int a) {
    if(a==parent[a]) return parent[a];
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a>b) swap(a, b);
    parent[b] = a;
}

bool sameParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    return a==b;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, a, b});
    }
    
    sort(v.begin(), v.end());
    int amt=0;
    for(int i=0; i<m; i++) {
        int a, b, c;
        tie(c, a, b) = v[i];
        if(getParent(a)==getParent(b)) continue;
        unionParent(a, b);
        edges.push_back(v[i]);
        amt += c; 
    }
    amt -= get<0>(edges.back());
    cout << amt;
}