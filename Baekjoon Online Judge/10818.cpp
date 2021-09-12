#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    int mn = 1000000;
    int mx = -1000000;
    while(n--) {
        int a;
        cin >> a;
        mn = min(mn, a);
        mx = max(mx, a);
    }

    cout << mn << ' ' << mx;
}