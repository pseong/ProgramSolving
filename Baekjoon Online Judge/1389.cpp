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
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    vector<int> v[150];
    int an[150][150]{0};
    for(int i=1; i<=130; i++) {
        for(int j=1; j<=130; j++) {
            an[i][j] = 1000000000;
            if(i==j) an[i][j] = 0;
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        an[a][b] = 1;
        an[b][a] = 1;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(an[i][j] > an[i][k]+an[k][j]) {
                    an[i][j] = an[i][k]+an[k][j];
                }
            }
        }
    }

    int ans[150]{0};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            ans[i] += an[i][j];
        }
    }
    int num=0;
    int cnt=1000000000;
    for(int i=1; i<=n; i++) {
        if(ans[i]<cnt) {
            num = i;
            cnt = ans[i];
        }
    }
    cout << num;
}