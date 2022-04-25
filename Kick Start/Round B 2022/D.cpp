#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int dx[4]{1, 0, -1, 0};
int dy[4]{0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int a, b;
        cin >> a >> b;
        int mp[400][400]{ 0 };
        string s[200];
        for (int i=0; i<a; i++) {
            cin >> s[i];
        }
        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                if (s[i][j] == '#') {
                    mp[i*2][j*2] = 1;
                    mp[i*2][j*2+1] = 1;
                    mp[i*2+1][j*2+1] = 1;
                    mp[i*2+1][j*2] = 1;
                }
            }
        }
        pair<int, int> now = {1, 0};
        mp[1][0] = 1;
        string ans = "S";
        while (now.first != 0 || now.second != 0) {
            int x, y;
            tie(x, y) = now;
            for (int d=0; d<4; d++) {
                int n = x+dx[d];
                int m = y+dy[d];
                if (n<0 || n>=2*a || m<0 || m>=2*b) continue;
                if (mp[n][m]) continue;
                mp[n][m] = 1;
                if (d == 0) {
                    ans.push_back('S');
                }
                else if (d == 1) {
                    ans.push_back('E');
                }
                else if (d == 2) {
                    ans.push_back('N');
                }
                else {
                    ans.push_back('W');
                }
                now = {n, m};
                break;
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}