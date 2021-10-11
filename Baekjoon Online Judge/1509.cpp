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

int pal[3000][3000];
int dp[3000];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++) {
        int go=i;
        int back=i;
        while(back>=0 && go<str.size() && str[go]==str[back]) {
            pal[back][go] = 1;
            back--;
            go++;
        }
    }
    for(int i=0; i<str.size()-1; i++) {
        int go=i+1;
        int back=i;
        while(back>=0 && go<str.size() && str[go]==str[back]) {
            pal[back][go] = 1;
            back--;
            go++;
        }
    }

    dp[0] = 1;
    for(int i=1; i<str.size(); i++) {
        dp[i] = dp[i-1]+1;
        for(int m=i/2; m<=i; m++) {
            int gap=i-m;
            int go=m+gap;
            int back=m-gap;
            if(back<0 || go>i) continue;
            if(pal[back][go]) {
                if(back==0) dp[i] = 1;
                else dp[i] = min(dp[i], dp[back-1]+1);
            }
        }
        for(int m=i/2; m<=i; m++) {
            int gap=i-m;
            int go=m+gap;
            int back=m-1-gap;
            if(back<0 || go>i) continue;
            if(pal[back][go]) {
                if(back==0) dp[i] = 1;
                else dp[i] = min(dp[i], dp[back-1]+1);
            }
        }
    }
    cout << dp[str.size()-1];
}