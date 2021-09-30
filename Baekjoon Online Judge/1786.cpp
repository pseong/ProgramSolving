#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int ans[1000010]{0};
int idx=0;
int table[1000010]{0};
string parent="";
string pattern="";

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    getline(cin, parent);
    getline(cin, pattern);

    int j=0; 
    for(int i=1; i<pattern.size(); i++) {
        while(j>0 && pattern[j]!=pattern[i]) {
            j = table[j-1];
        }
        if(pattern[j]==pattern[i]) {
            table[i] = j+1;
            j++;
        }
    }

    j=0;
    for(int i=0; i<parent.size(); i++) {
        while(j>0 && pattern[j]!=parent[i]) {
            j = table[j-1];
        }
        if(pattern[j]==parent[i]) {
            if(j==pattern.size()-1) {
                ans[idx] = i-pattern.size()+2;
                idx++;
                j = table[j];
            } else {
                j++;
            }
        }
    }
    cout << idx << '\n';
    for(int i=0; i<idx; i++) {
        cout << ans[i] << ' ';
    }
}