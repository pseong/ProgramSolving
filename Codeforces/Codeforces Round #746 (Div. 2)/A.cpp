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

bool func(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n, h; 
        cin >> n >> h;
        vector<ll> an;
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            an.push_back(a);
        }
        sort(an.begin(), an.end(), func);
        ll sum=an[0]+an[1];
        ll cnt=h/sum;
        h -= cnt*sum;
        cnt = 2*cnt;
        if(h<=0) cout << cnt << '\n';
        else {
            h -= an[0];
            if(h<=0) cout << cnt + 1 << '\n';
            else {
                h -= an[1];
                if(h<=0) cout << cnt + 2 << '\n';
            }
        }
    }
}