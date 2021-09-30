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

int table[1010]{0};
string parent="";
int len;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> len;
    cin >> parent;

    int j=0;
    for(int i=1; i<parent.size(); i++) {
        while(j>0 && parent[j]!=parent[i]) {
            j = table[j-1];
        }
        if(parent[j]==parent[i]) {
            table[i] = j+1;
            j++;
        }
    }
    cout << len-table[len-1];
}