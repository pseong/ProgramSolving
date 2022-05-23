#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
 
int main(void) {
	cin.tie(0)->sync_with_stdio(0);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            mp[a]++;
        }
        int left = 0;
        int right = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second >= 2) {
                left++;
                right++;
            }
            else {
                if (left < right) left++;
                else right++;
            }
        }
        cout << max(left, right) << '\n';
    }
    return 0;
}