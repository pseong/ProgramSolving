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

    int n, m;
    cin >> n >> m;
    int visit[1010]{0};
    vector<int> v[1010];
    for(int i=0; i<m; i++) {
        int a;
        cin >> a;
        vector<int> nums;
        while(a--) {
            int b;
            cin >> b;
            nums.push_back(b);
        }
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                v[nums[i]].push_back(nums[j]);
                visit[nums[j]]++;
            }
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(visit[i]==0) q.push(i);
    }

    vector<int> ans;
    bool fail=false;
    for(int i=1; i<=n; i++) {
        if(q.empty()) {
            fail = true;
            break;
        }
        int a=q.front();
        q.pop();
        ans.push_back(a);
        for(int j : v[a]) {
            visit[j]--;
            if(visit[j]==0) {
                q.push(j);
            }
        }
    }
    if(fail) cout << "0";
    else {
        for(int i : ans) {
            cout << i << '\n';
        }
    }
}