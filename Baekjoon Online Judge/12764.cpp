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

    int n;
    cin >> n;
    vector<pii> v;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    set<int> left;
    int ans=0;
    int ans2[100010]{0};
    for(int i=0; i<v.size(); i++) {
        while(!pq.empty()) {
            if(pq.top().F<=v[i].F) {
                left.insert(pq.top().S);
                pq.pop();
            }
            else break;
        }
        if(!left.empty()) {
            auto idx=left.begin();
            pq.push({v[i].S, *idx});
            left.erase(idx);
            ans2[*idx]++;
        }
        else {
            ans++;
            pq.push({v[i].S, ans});
            ans2[ans]++;
        }
    }
    cout << ans << '\n';
    for(int i=1; i<=ans; i++) {
        cout << ans2[i] << ' ';
    }
}