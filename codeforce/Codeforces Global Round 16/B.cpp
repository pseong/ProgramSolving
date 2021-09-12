#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans=0;
        bool hole_0=false;
        bool hole_1=false;
        bool pre_0=false;
        bool pre_1=false;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='0') {
                hole_0=true;
                if(pre_1) {
                    pre_1=false;
                    pre_0=true;
                } else {
                    pre_0=true;
                }
            } else {
                hole_1=true;
                if(pre_0) {
                    ans++;
                    pre_0=false;
                    pre_1=true;
                } else {
                    pre_1=true;
                }
            }
        }
        if(pre_0) ans++;
        if(hole_0&&hole_1&&ans>2) ans = 2;
        cout << ans << '\n';
    }
}