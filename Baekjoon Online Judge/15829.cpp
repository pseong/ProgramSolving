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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    
    ll ans=0;
    for(int i=0; i<s.size(); i++) {
        int a = s[i]-96;
        ll p=1;
        for(int j=0; j<i; j++) {
            p *= 31;
            p %= 1234567891;
        }
        ans += (a*p)%1234567891;
        ans %= 1234567891;
    }
    cout << ans;
}