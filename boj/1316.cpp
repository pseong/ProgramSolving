#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int ans=0;
    while(n--) {
        int use[300]{0};
        string s;
        cin >> s;
        bool group=true;
        int pre=0;
        for(int i=0; i<s.size(); i++) {
            if(!use[s[i]]) {
                use[s[i]] = 1;
                pre=s[i];
            } else {
                if(pre!=s[i]) {
                    group=false;
                    break;
                }
            }
        }
        if(group) ans++;
    }
    cout << ans;
}