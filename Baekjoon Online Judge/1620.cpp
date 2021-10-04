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

string str[100010];
map<string, int> mp;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        str[i] = s;
        mp[s] = i;
    }

    for(int i=0; i<m; i++) {
        string s;
        cin >> s;
        if(s[0]>=65&&s[0]<=90) {
            cout << mp[s] << '\n';
        } else {
            cout << str[stoi(s)] << '\n';
        }
    }
}