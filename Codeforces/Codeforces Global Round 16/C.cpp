#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s[2];
        int n;
        cin >> n >> s[0] >> s[1];
        int ans=0;
        bool pre_0=false;
        bool pre_1=false;
        for(int i=0; i<n; i++) {
            if(s[0][i]=='0'&&s[1][i]=='1' ||
                s[0][i]=='1'&&s[1][i]=='0') {
                    ans+=2;
                    pre_0=false;
                    pre_1=false;
                }
            else if(s[0][i]=='0'&&s[1][i]=='0') {
                ans++;
                if(pre_1) {
                    ans++;
                }
                else if(i+1<n) {
                    if(s[0][i+1]=='1'&&s[1][i+1]=='1') {
                        ans++;
                        i++;
                    }
                }
                pre_0=false;
                pre_1=false;
            } else {
                pre_1=true;
            }
        }
        cout << ans << '\n';
    }
}