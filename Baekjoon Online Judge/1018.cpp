#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int b[55][55]{ 0 };
    
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            b[i][j+1] = s[j];
        }
    }

    int ans = 64;
    for(int i = 1; i + 7 <= n; i++) {
        for(int j = 1; j + 7 <= m; j++) {
            int now = 'W';
            int late = 'B';
            int cnt = 0;
            for(int h = i; h <= i + 7; h++) {
                for(int w = j; w <= j + 7; w++) {
                    if(b[h][w] != now) cnt++;
                    swap(now, late);
                }
                swap(now, late);
            }
            swap(now, late);
            ans = min(ans, cnt);
            cnt = 0;
            for(int h = i; h <= i + 7; h++) {
                for(int w = j; w <= j + 7; w++) {
                    if(b[h][w] != now) cnt++;
                    swap(now, late);
                }
                swap(now, late);
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans;
}