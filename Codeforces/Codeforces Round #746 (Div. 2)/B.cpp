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

vector<int> an(100010);
vector<int> an2(100010);
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        for(int i=0; i<n; i++) {
            cin >> an[i];
            an2[i] = an[i];
        }
        sort(an2.begin(), an2.begin()+n);
        bool s=true;
        for(int i=n-x; i<x; i++) {
            if(an[i]!=an2[i]) {
                s = false;
                break;
            }
        }
        if(s) cout << "YES\n";
        else cout << "NO\n";
        an.clear();
        an2.clear();
    }
}