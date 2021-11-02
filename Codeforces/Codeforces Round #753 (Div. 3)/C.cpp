#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, a;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++) {
            cin >> a;
            pq.push(a);
        }
        int add=0;
        int ans=pq.top();
        while(pq.size()>1) {
            add = -pq.top();
            pq.pop();
            ans = max(ans, pq.top()+add);
        }
        cout << ans << '\n';
    }
}