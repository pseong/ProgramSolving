#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    deque<int> dq;
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    int an[100]{0};
    for(int i=0; i<m; i++) {
        cin >> an[i];
    }

    int ans=0;
    for(int i=0; i<m; i++) {
        int fi=an[i];
        int cnt=0;
        while(q.front()!=fi) {
            cnt++;
            q.push(q.front());
            q.pop();
        }
        cnt = min((int)q.size()-cnt, cnt);
        q.pop();
        ans += cnt;
    }
    cout << ans;
}