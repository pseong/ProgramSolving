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

void hanoi(int n, ll k, int from, int to, int by) {
    if(n==1) {
        cout << from << ' ' << to;
        return;
    }

    ll cnt=((2ll<<n-1)-1)/2;
    if(k<=cnt) {
        hanoi(n-1, k, from, by, to);
    }
    else if(k==cnt+1) {
        cout << from << ' ' << to;
    }
    else {
        hanoi(n-1, k-cnt-1, by, to, from);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    hanoi(n, k, 1, 3, 2);
}