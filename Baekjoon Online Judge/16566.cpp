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

int n, m, k, am[4000010], ak[10010], parent[4000010];

int getParent(int a) {
    if(parent[a]==a) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a<b) swap(a, b);
    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        cin >> am[i];
    }
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<k; i++) {
        cin >> ak[i];
    }
    sort(am, am+m+1);
    for(int i=1; i<=m; i++) {
        for(int z=am[i-1]+1; z<am[i]; z++) {
            unionParent(z, z+1);
        }
    }

    for(int i=0; i<k; i++) {
        int see=ak[i];
        int a=getParent(ak[i]+1);
        unionParent(a, a+1);
        cout << a << '\n';
    }
}