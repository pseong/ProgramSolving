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
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        int i = 0;
        while (true) {
            if (i >= n-1) break;
            if (s[i] == ')' && s[i+1] == '(') {
                int j = i+2;
                while (j<n && s[j]=='(') j++;
                if (j==n) break;
                else {
                    ans++;
                    i = j+1;
                }
            }
            else {
                ans++;
                i += 2;
            }
        }
        cout << ans << ' ' << n-i << '\n';
    }
}