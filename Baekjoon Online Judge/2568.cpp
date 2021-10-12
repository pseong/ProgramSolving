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

    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());

    int idx=0;
    int arr[100010]{0};
    int trace[100010]{0};
    for(int i=0; i<n; i++) {
        if(idx>0 && arr[idx-1]>v[i].second) {
            int a=lower_bound(arr, arr+idx, v[i].second)-arr;
            arr[a] = v[i].second;
            trace[i] = a;
        }
        else {
            arr[idx] = v[i].second;
            trace[i] = idx;
            idx++;
        }
    }
    cout << n-idx << '\n';
    int cur=idx-1;
    bool block[100010]{0};
    for(int i=n-1; i>=0; i--) {
        if(trace[i]==cur) {
            block[i] = 1;
            //arr[cur] = v[i].first;
            cur--;
        }
    }
    for(int i=0; i<v.size(); i++) {
        if(block[i]) continue;
        cout << v[i].first << '\n';
    }
}