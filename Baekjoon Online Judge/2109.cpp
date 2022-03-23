#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool f(pair<int, int>& l, pair<int, int>& r) {
    if (l.first != r.first) return l.first > r.first;
    else return l.second < r.second;
}

bool calen[10101];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i=1; i<=n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back({p, d});
    }
    sort(v.begin(), v.end(), f);

    int ans = 0;
    for (int i=0; i<v.size(); i++) {
        int p = v[i].first;
        int d = v[i].second;
        int k = d;
        for (; k>=1; k--) {
            if (!calen[k]) break;
        }
        if (!k) continue;
        calen[k] = 1;
        ans += p;
    }
    cout << ans;
}