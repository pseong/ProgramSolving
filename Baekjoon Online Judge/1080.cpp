#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int an[60][60], bn[60][60];
int n, m, ans;

void flip(int i, int j) {
    for (int a=i; a<=i+2; a++) {
        for (int b=j; b<=j+2; b++) {
            an[a][b] = 1-an[a][b];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        for (int j=0; j<s.size(); j++) {
            an[i][j+1] = s[j]-'0';
        }
    }

    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        for (int j=0; j<s.size(); j++) {
            bn[i][j+1] = s[j]-'0';
        }
    }

    for (int i=1; i<=n-2; i++) {
        for (int j=1; j<=m-2; j++) {
            if (an[i][j] != bn[i][j]) {
                ans++;
                flip(i, j);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (an[i][j] != bn[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
}