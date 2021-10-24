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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans=1000000000;
        for(int i=0; i<26; i++) {
            int left=0;
            int right=n-1;
            int res=0;
            while(left<=right) {
                if(s[left]==s[right]) {
                    left++;
                    right--;
                }
                else {
                    if(s[left]==('a'+i)) {
                        res++;
                        left++;
                    }
                    else if(s[right]==('a'+i)) {
                        res++;
                        right--;
                    }
                    else {
                        res = 1000000000;
                        break;
                    }
                }
            }
            ans = min(ans, res);
        }
        if(ans==1000000000) cout << -1;
        else cout << ans;
        cout << '\n';
    }
}