#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int E, S, M;
    cin >> E >> S >> M;

    int ans = 1;
    int e = 1;
    int s = 1;
    int m = 1;
    while(true) {
        if(e == E && s == S && m == M) {
            cout << ans;
            return 0;
        }
        e++;
        s++;
        m++;
        if(e==16) e = 1;
        if(s==29) s = 1;
        if(m==20) m = 1;
        ans++;
    }
}