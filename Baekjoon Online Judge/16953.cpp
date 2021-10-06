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
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> a >> b;
    queue<pll> bfs;
    bfs.push({a, 0});
    ll ans=-1;
    while(!bfs.empty()) {
        ll v, w;
        tie(v, w)=bfs.front();
        bfs.pop();
        if(v==b) {
            ans = w+1;
            break;
        }
        if(v*2<=1000000000) {
            bfs.push({v*2, w+1});
        }
        if(v*10+1<=1000000000) {
            bfs.push({v*10+1, w+1});
        }
    }
    cout << ans;
}