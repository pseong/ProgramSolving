#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> an;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        an.clear();
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            an.push_back(a);
        }
        sort(an.begin(), an.end());
        bool good = false;
        for (int i=0; i<n; i++) {
            int see = an[i];
            auto it = lower_bound(an.begin(), an.end(), see+k);
            if (it != an.end() && *it == see+k) {
                good = true;
                break;
            }
        }

        if (good) cout << "YES\n";
        else cout << "NO\n";
    }
}