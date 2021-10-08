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
    vector<pii> police;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        police.push_back({a, b});
    }
    int x, y;
    cin >> x >> y;

    bool exit=true;
    for(int i=0; i<n; i++) {
        if(police[i].first>x) {
            if(abs(police[i].second-y) <= abs(police[i].first-x)) {
                exit = false;
                break;
            }
        }
    }
    if(exit) {
        cout << "YES";
        return 0;
    }

    exit=true;
    for(int i=0; i<n; i++) {
        if(police[i].first<x) {
            if(abs(police[i].second-y) <= abs(police[i].first-x)) {
                exit = false;
                break;
            }
        }
    }
    if(exit) {
        cout << "YES";
        return 0;
    }

    exit=true;
    for(int i=0; i<n; i++) {
        if(police[i].second>y) {
            if(abs(police[i].second-y) >= abs(police[i].first-x)) {
                exit = false;
                break;
            }
        }
    }
    if(exit) {
        cout << "YES";
        return 0;
    }

    exit=true;
    for(int i=0; i<n; i++) {
        if(police[i].second<y) {
            if(abs(police[i].second-y) >= abs(police[i].first-x)) {
                exit = false;
                break;
            }
        }
    }
    if(exit) cout << "YES";
    else cout << "NO";
}