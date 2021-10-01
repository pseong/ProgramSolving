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
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int table[200010][20]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int am[200010]{0};
    int m;
    cin >> m;
    for(int i=1; i<=m; i++) {
        cin >> am[i];
    }
    
    for(int i=1; i<=m; i++) {
        table[i][0] = am[i];
    }

    for(int k=1; k<=19; k++) {
        for(int i=1; i<=m; i++) {
            table[i][k] = table[table[i][k-1]][k-1];
        }
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int n, x;
        cin >> n >> x;
        for(int k=19; k>=0; k--) {
            if(n>=(1<<k)) {
                x = table[x][k];
                n -= (1<<k);
            }
        }
        cout << x << '\n';
    }
}