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

int g, p, gi[100010];
int visit[100010];

int parent[100010];

int getParent(int a) {
    if(a==parent[a]) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a>b) swap(a, b);
    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> g >> p;
    for(int i=1; i<=p; i++) {
        cin >> gi[i];
    }
    for(int i=1; i<=g; i++) {
        parent[i] = i;
    }

    int ans=0;
    for(int i=1; i<=p; i++) {
        int k=getParent(gi[i]);
        if(k<1) break;
        ans++;
        unionParent(k, k-1);
    }
    cout << ans;
}