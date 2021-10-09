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

    int t;
    cin >> t;
    while(t--) {
        int n;
        char c;
        string s; 
        cin >> n >> c >> s;
        int case1=0;
        int case2=0;
        int dont[300010]{0};
        dont[1] = 1;
        for(int i=0; i<n; i++) {
            if(s[i]!=c) {
                int see=i+1;
                for(int j=2; j*j<=see; j++) {
                    while(see%j==0) {
                        dont[j] = 1;
                        dont[see/j] = 1;
                        see /= j;
                    }
                }
                dont[i+1] = 1;
                if(i==n-1) {
                    case2 = 1;
                } else {
                    case1 = 1;
                }
            }
        }
        if(case1==0&&case2==0) {
            cout << 0 << '\n';
        }
        else if(case1==0&&case2==1) {
            cout << 1 << '\n' << n-1 << '\n';
        }
        else if(case1==1&&case2==0) {
            cout << 1 << '\n' << n << '\n';
        }
        else {
            int f=0;
            for(int i=1; i<=n; i++) {
                if(dont[i]==0) {
                    f=i;
                    break;
                }
            }
            if(f) {
                cout << 1 << '\n' << f << '\n';
            }
            else {
                cout << 2 << '\n' << n << '\n' << n-1 << '\n';
            }
        }
    }
}