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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        int mini=0;
        if(m<n-1||m>n*(n-1)/2) {
            cout << "NO\n";
            continue;
        }
        else if(m==n*(n-1)/2) {
            mini = 1;
            if(n==1) mini = 0;
        }
        else if(m>=n-1 && m<n*(n-1)/2) {
            mini = 2;
        }

        if(mini<k-1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}