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

    vector<int> v;
    for(int i=1; i<225; i++) {
        v.push_back(i*i);
    }

    int n;
    cin >> n;
    for(int i=0; i<v.size(); i++) {
        if(v[i]==n) {
            cout << 1;
            return 0;
        }
    }

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(v[i]+v[j]==n) {
                cout << 2;
                return 0;
            }
        }
    }

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            for(int k=0; k<v.size(); k++) {
                if(v[i]+v[j]+v[k]==n) {
                    cout << 3;
                    return 0;
                }
            }
        }
    }
    cout << 4;
    return 0;
}