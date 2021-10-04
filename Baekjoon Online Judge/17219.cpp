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

map<string, string> mp;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    for(int i=0; i<m; i++) {
        string str;
        cin >> str;
        cout << mp[str] << '\n';
    }
}