#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> v;

int ans[200]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int idx=0;
    for(int i=0; i<n; i++) {
        if(idx>0&&ans[idx-1]>=v[i].second) {
            int a=lower_bound(ans, ans+idx, v[i].second)-ans;
            ans[a] = v[i].second;
        } else {
            ans[idx] = v[i].second;
            idx++;
        }
    }
    cout << n-idx;
}