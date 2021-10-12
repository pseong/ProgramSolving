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

ll sum(ll a) {
    ll ret=0;
    for(ll i=2; i<1000000000000000000; i*=2) {
        ll s=a+1;
        ret += s/i*i/2;
        s %= i;
        s -= i/2;
        if(s>0) ret += s;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> a >> b;
    cout << sum(b)-sum(a-1);
}