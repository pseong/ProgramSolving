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
        string s;
        cin >> s;
        int n = s.size();
        bool ex[26]{ 0 };
        int ans = 0;
        for (int i=n-1; i>=0; i--) {
            if (!ex[s[i]-'a']) {
                ans = i;
                ex[s[i]-'a'] = true;
            }
        }
        cout << s.substr(ans) << '\n';
    }
}