#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> an;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            an.push_back(a);
        }
        sort(an.begin(), an.end());
        an.push_back(an[0]);
        vector<int> gap;
        for (int i=0; i<an.size()-1; i++) {
            gap.push_back(max(an[i], an[i+1]));
        }
        ll sum = accumulate(gap.begin(), gap.end(), 0ll);
        if (m - sum - n >= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}