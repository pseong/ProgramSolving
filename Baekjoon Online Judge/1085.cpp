#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int ans = x;
    ans = min(ans, w-x);
    ans = min(ans, y);
    ans = min(ans, h-y);
    cout << ans;
}