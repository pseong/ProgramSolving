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
    while(T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> ans(n, 0);
        string out;
        bool b = k&1;
        for (int i=0; i<n; i++) {
            bool a = s[i]-'0';
            a ^= b;
            s[i] = a+'0';
            if (a == 0 && k) {
                ans[i]++;
                k--;
                s[i] = '1';
            }
        }
        ans[n-1] += k;
        if (k&1) s[n-1] = '0'; 
        cout << s << '\n';
        for (int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}