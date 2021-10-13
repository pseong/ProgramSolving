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
using pdd = pair<double, double>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans=1000000000;
        bool one=false;
        bool two=false;
        int i=s.size()-1;
        for(; i>=0; i--) {
            if(one) {
                if(s[i]=='0') {
                    two = true;
                    break;
                }
            } else {
                if(s[i]=='0') one = true;
            }
        }
        if(one&&two) {
            int res=s.size()-i-2;
            ans = min(ans, res);
        }

        one=false;
        two=false;
        i=s.size()-1;
        for(; i>=0; i--) {
            if(one) {
                if(s[i]=='2') {
                    two = true;
                    break;
                }
            } else {
                if(s[i]=='5') one = true;
            }
        }
        if(one&&two) {
            int res=s.size()-i-2;
            ans = min(ans, res);
        }

        one=false;
        two=false;
        i=s.size()-1;
        for(; i>=0; i--) {
            if(one) {
                if(s[i]=='5') {
                    two = true;
                    break;
                }
            } else {
                if(s[i]=='0') one = true;
            }
        }
        if(one&&two) {
            int res=s.size()-i-2;
            ans = min(ans, res);
        }

        one=false;
        two=false;
        i=s.size()-1;
        for(; i>=0; i--) {
            if(one) {
                if(s[i]=='7') {
                    two = true;
                    break;
                }
            } else {
                if(s[i]=='5') one = true;
            }
        }
        if(one&&two) {
            int res=s.size()-i-2;
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}