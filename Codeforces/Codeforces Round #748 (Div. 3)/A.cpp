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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll see=max({a, b, c});
        bool many=false;
        if(a==see&&b==see||a==see&&c==see||b==see&&c==see) many = true;
        if(!many) {
            if(a!=see) cout << abs(a-see)+1 << ' ';
            else cout << 0 << ' ';
            if(b!=see) cout << abs(b-see)+1 << ' ';
            else cout << 0 << ' ';
            if(c!=see) cout << abs(c-see)+1 << ' ';
            else cout << 0 << ' ';
            cout << '\n';
        }
        else {
            if(a!=see) cout << abs(a-see)+1 << ' ';
            else cout << 1 << ' ';
            if(b!=see) cout << abs(b-see)+1 << ' ';
            else cout << 1 << ' ';
            if(c!=see) cout << abs(c-see)+1 << ' ';
            else cout << 1 << ' ';
            cout << '\n';
        }
    }
}