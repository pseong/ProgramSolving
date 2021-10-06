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

    int n;
    cin >> n;
    ll an[100010]{0};
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    sort(an, an+n);
    int s=0;
    int e=n-1;
    int ans_s=0;
    int ans_e=n-1;
    ll ans=2000000000;
    while(s<e) {
        ll res=an[s]+an[e];
        if(abs(ans)>abs(res)) {
            ans = abs(res);
            ans_s = s;
            ans_e = e;
        }
        if(res>0) e--;
        else if(res<0) s++;
        else break;
    }
    cout << an[ans_s] << ' ' << an[ans_e];
}