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
        int cnt[500];
        memset(cnt, 0, sizeof cnt);
        string s;
        cin >> s;
        for (int i=0; i<s.size(); i++) {
            cnt[s[i]]++;
        }
        int cur = 0;
        while (true) {
            if (cur<s.size() && cnt[s[cur]] > 1) {
                cnt[s[cur]]--;
                cur++;
            }
            else break;
        }
        for (int i=cur; i<s.size(); i++) {
            cout << s[i];
        }
        cout << '\n';
    }
}