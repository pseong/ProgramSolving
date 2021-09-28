#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <tuple>

typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int mask=0;
    int m;
    cin >> m;
    while(m--) {
        string str;
        cin >> str;
        int a;
        if(str=="add") {
            cin >> a;
            mask |= (1<<a);
        } else if(str=="remove") {
            cin >> a;
            mask &= ~(1<<a);
        } else if(str=="check") {
            cin >> a;
            if(mask&(1<<a)) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if(str=="toggle") {
            cin >> a;
            mask ^= (1<<a);
        } else if(str=="all") {
            mask = ~0;
        } else if(str=="empty") {
            mask = 0;
        }
    }
}