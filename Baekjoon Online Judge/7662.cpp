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

    int t;
    cin >> t;
    while(t--) {
        multiset<int> ms;
        int k;
        cin >> k;
        while(k--) {
            char c;
            cin >> c;
            if(c=='I') {
                int n;
                cin >> n;
                ms.insert(n);
            } else if(c=='D') {
                int n;
                cin >> n;
                if(ms.empty()) continue;
                if(n==1) ms.erase(--ms.end());
                else if(n==-1) ms.erase(ms.begin());
            }
        }
        if(ms.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *--ms.end() << ' ' << *ms.begin() << '\n';
        }
    }
}