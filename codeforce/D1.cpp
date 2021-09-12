#include <iostream>
#include <vector>
#include <algorithm>

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
    int s[301]{0};

    int seat[301]{0};
    vector<pair<int, int>> v;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=1; i<=m; i++) {
            int a;
            cin >> a;
            v.push_back({a, i});
        }
        sort(v.begin(), v.end(), func);
        for(int i=0; i<m; i++) {
            s[v[i].second] = i+1;
        }
        int ans=0;
        for(int i=1; i<=m; i++) {
            for(int j=1; j<s[i]; j++) {
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