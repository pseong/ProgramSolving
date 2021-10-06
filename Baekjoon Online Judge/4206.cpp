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

string fib[200];
int sum_idx[200]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    fib[0] = "0";
    fib[1] = "1";
    for(int i=2; i<=30; i++) {
        fib[i] = fib[i-1]+fib[i-2];
        sum_idx[i] = fib[i-1].size();
    }

    int n;
    string p;
    int idx=1;
    while(cin >> n) {
        cin >> p;
        int table[100010]{0};
        int j=0;
        for(int i=1; i<p.size(); i++) {
            while(j!=0 && p[i]!=p[j]) {
                j = table[j-1];
            }
            if(p[i]==p[j]) {
                table[i] = ++j;
            }
        }

        ll dp[200]{0};
        if(fib[0]==p) dp[0] = 1;
        if(fib[1]==p) dp[1] = 1;
        int odd_plus=0;
        int even_plus=0;
        for(int k=2; k<=n; k++) {
            dp[k] = dp[k-1]+dp[k-2];
            if(k>30) {
                if(k%2==0) dp[k] += even_plus;
                else dp[k] += odd_plus;
            } else {
                if(k%2==0) even_plus = 0;
                else odd_plus = 0;
                int j=0;
                int start=sum_idx[k]-p.size()+1;
                int end=sum_idx[k]+p.size()-1;
                for(int i=start; i<end; i++) {
                    if(i<0) i = 0;
                    if(i>=fib[k].size()) break;
                    char one=fib[k][i];
                    char two=p[j];
                    while(j!=0 && fib[k][i] != p[j]) {
                        j = table[j-1];
                    }
                    if(fib[k][i]==p[j]) {
                        if(j==p.size()-1) {
                            if(k%2==0) even_plus++;
                            else odd_plus++;
                            j = table[j];
                        }
                        else {
                            j++;
                        }
                    }
                }
                if(k%2==0) dp[k] += even_plus;
                else dp[k] += odd_plus;
            }
        }
        cout << "Case " << idx << ": " << dp[n] << '\n';
        idx++;
    }
}