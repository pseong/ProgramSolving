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
        char min_char='z';
        int min_idx=0;
        for(int i=0; i<s.size(); i++) {
            if(min_char>s[i]) {
                min_char = s[i];
                min_idx = i;
            }
        }
        cout << min_char << ' ';
        for(int i=0; i<s.size(); i++) {
            if(i==min_idx) continue;
            cout << s[i];
        }
        cout << '\n';
    }
}