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

int n, m;
int inDegree[35000]{0};
vector<int> v[35000];
int ans[35000]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> que;
    for(int i=1; i<=n; i++) {
        if(inDegree[i]==0) que.push(i);
    }
    for(int i=1; i<=n; i++) {
        if(que.empty()) {
            cout << -1;
            break;
        }
        int a = que.front();
        que.pop();
        ans[i] = a;
        for(int b : v[a]) {
            if(--inDegree[b]==0) que.push(b);
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
}