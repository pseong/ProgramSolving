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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
 
        int x=0;
        int y=0;
        int max_x=0;
        int min_x=0;
        int max_y=0;
        int min_y=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='U') {
                x--;
                int tmp = min_x;
                min_x = min(min_x, x);
                if(max_x-min_x > n-1) {
                    x++;
                    min_x = tmp;
                    break;
                }
            }
            else if(s[i]=='D') {
                x++;
                int tmp = max_x;
                max_x = max(max_x, x);
                if(max_x-min_x > n-1) {
                    x--;
                    max_x = tmp;
                    break;
                }
            }
            else if(s[i]=='R') {
                y++;
                int tmp = max_y;
                max_y = max(max_y, y);
                if(max_y-min_y > m-1) {
                    max_y = tmp;
                    y--;
                    break;
                }
            }
            else if(s[i]=='L') {
                y--;
                int tmp = min_y;
                min_y = min(min_y, y);
                if(max_y-min_y > m-1) {
                    y++;
                    min_y = tmp;
                    break;
                }
            }
        }
        cout << abs(min_x)+1 << ' ' << abs(min_y)+1 << '\n';
    }
}