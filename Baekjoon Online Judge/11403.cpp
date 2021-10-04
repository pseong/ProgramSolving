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

    int n;
    int an[110][110]{0};
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
            if(an[i][j]==0)
                an[i][j] = 1000000000;
        }
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(an[i][j] > an[i][k]+an[k][j]) {
                    an[i][j] = an[i][k]+an[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int a=an[i][j];
            if(a==1000000000) a = 0;
            else a = 1;
            cout << a << ' ';
        }
        cout << '\n';
    }
}