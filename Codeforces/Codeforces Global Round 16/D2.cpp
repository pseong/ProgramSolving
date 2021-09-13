#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool func(pair<int, int> a, pair<int, int> b) {
    if(a.first==b.first) {
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    int s[500]{0};

    int seat[500]{0};
    vector<pair<int, int>> v;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=1; i<=n*m; i++) {
            int a;
            cin >> a;
            v.push_back({a, i});
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++) {
            sort(v.begin()+i*m, v.begin()+(i+1)*m, func);
        }
        for(int i=0; i<n*m; i++) {
            s[v[i].second] = i+1;
        }
        int ans=0;
        for(int i=1; i<=m*n; i++) {
            int a=ceil((double)s[i]/m);
            int b=(s[i]-1)%m+1;
            for(int j=(a-1)*m+1; j<s[i]; j++) {
                if(seat[j]) ans++;
            }
            seat[s[i]] = 1;
        }
        cout << ans << '\n';
        v.clear();
        for(int i=0; i<=300; i++) {
            s[i]=0;
            seat[i]=0;
        }
    }
}