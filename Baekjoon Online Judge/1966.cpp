#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            q.push({a, i});
        }
        int ans[103]{0};
        int idx=1;
        while(!q.empty()) {
            int mx=0;
            for(int i=0; i<q.size(); i++) {
                auto a=q.front();
                mx = max(mx, a.first);
                q.pop();
                q.push(a);
            }
            if(mx>q.front().first) {
                q.push(q.front());
                q.pop();
            } else {
                ans[q.front().second] = idx;
                idx++;
                q.pop();
            }
        }
        cout << ans[m] << '\n';
    }
}