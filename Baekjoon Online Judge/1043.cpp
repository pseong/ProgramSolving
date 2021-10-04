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

    int n, m, g;
    cin >> n >> m >> g;
    int an[100]{0};
    for(int i=0; i<g; i++) {
        int a;
        cin >> a;
        an[a] = true;
    }

    vector<int> party[100];
    for(int i=0; i<m; i++) {
        int nums;
        cin >> nums;
        for(int j=0; j<nums; j++) {
            int a;
            cin >> a;
            party[i].push_back(a);
        }
    }

    for(int cnt=0; cnt<=m; cnt++) {
        for(int i=0; i<m; i++) {
            bool flag=false;
            for(int k : party[i]) {
                if(an[k]) flag = true;
            }
            if(flag) {
                for(int k : party[i]) {
                    an[k] = true;
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<m; i++) {
        bool flag=false;
        for(int k : party[i]) {
            if(an[k]) flag = true;
        }
        if(!flag) ans++;
    }
    cout << ans;
}