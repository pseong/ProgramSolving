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
        int an[1010]{0};
        vector<int> v[1010];
        int inDegree[1010]{0};
        int n, k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        for(int i=0; i<k; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            inDegree[b]++;
        }
        int w;
        cin >> w;

        int ans[1010]{0};
        queue<int> que;
        for(int i=1; i<=n; i++) {
            if(inDegree[i]==0) {
                ans[i] = an[i];
                que.push(i);
            }
        }
        for(int i=1; i<=n; i++) {
            int a;
            a = que.front();
            que.pop();
            for(int j : v[a]) {
                ans[j] = max(ans[j], ans[a]+an[j]);
                inDegree[j]--;
                if(inDegree[j]==0) {
                    que.push(j);
                }
            }
        }
        cout << ans[w] << '\n';
    }
}