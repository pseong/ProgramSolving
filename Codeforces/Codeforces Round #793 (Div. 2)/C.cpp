#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            mp[a]++;
        }
        int left = 0;
        int right = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            if (it->second >= 2) {
                left++;
                right++;
                continue;
            }
            else {
                if (left < right) left++;
                else right ++;
            }
        }
        cout << max(left, right) << '\n';
    }
}