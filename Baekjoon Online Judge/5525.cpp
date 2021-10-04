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

bool func(pii a, pii b) {
    return a.first > b.first;
}

pii d[300010];
multiset<int> ms;
int cnt=0;
int len=0;
int n, m;
string s;

void f() {
    if(len<3) return;
    if(len%2==0) len--;
    len = len-n+1;
    if(len<0) return;
    len = len-len/2;
    cnt += len;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s;
    n = n*2+1;

    for(int i=0; i<m; i++) {
        if(s[i]=='I') {
            if(len%2==0) len++;
            else {
                f();
                len = 1;
            }
        }
        else if(s[i]=='O') {
            if(len%2==1) len++;
            else {
                f();
                len = 0;
            }
        }
    }
    f();
    cout << cnt;
}