#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n;

char flip(char c) {
    if (c == 'H') return 'T';
    else return 'H';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<string> s(n);
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    int ans = n*n;
    for (int o=0; o<(1<<n); o++) {
        int total = 0;
        for (int j=0; j<n; j++) {
            int cnt = 0;
            for (int i=0; i<n; i++) {
                char cur = s[i][j];
                if (o & (1<<i)) {
                    cur = flip(cur);
                }
                if (cur=='H') cnt++;
            }
            total += min(cnt, n-cnt);
        }
        ans = min(ans, total);
    }
    cout << ans;
}