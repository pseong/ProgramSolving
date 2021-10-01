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

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int an[600]{0};
        int inDegree[600]{0};
        vector<int> v[600];

        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            an[i] = a;
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                v[an[i]].push_back(an[j]);
                inDegree[an[j]]++;
            }
        }
        int m;
        cin >> m;
        bool fail=false;
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            auto it=find(v[b].begin(), v[b].end(), a);
            if(it!=v[b].end()) {
                v[b].erase(it);
                v[a].push_back(b);
                inDegree[a]--;
                inDegree[b]++;
            } else {
                it=find(v[a].begin(), v[a].end(), b);
                v[a].erase(it);
                v[b].push_back(a);
                inDegree[a]++;
                inDegree[b]--;
            }
        }
        if(fail) continue;

        queue<int> que;
        for(int i=1; i<=n; i++) {
            if(inDegree[i]==0) que.push(i);
        }

        int ans[600]{0};
        fail=false;
        for(int i=1; i<=n; i++) {
            if(que.empty()) {
                cout << "IMPOSSIBLE\n";
                fail = true;
                break;
            }
            int a = que.front();
            que.pop();
            ans[i] = a;
            for(int b : v[a]) {
                if(--inDegree[b]==0) que.push(b);
            }
        }
        if(fail) continue;

        for(int i=1; i<=n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}