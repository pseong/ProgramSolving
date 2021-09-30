#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
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

ll factorial(int a) {
    ll res=1;
    for(int i=1; i<=a; i++) {
        res *= i;
        if(res==2) res /= 2;
        res %= 1000000007;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << factorial(n*2) << '\n';
    }
}