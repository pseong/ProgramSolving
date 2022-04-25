#include <bits/stdc++.h>
# define PI           3.14159265358979323846

using namespace std;
using ll=long long;

string I, P;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    cout << fixed << setprecision(6);
    for (int i=1; i<=T; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        double radius = r;
        double ans = radius*radius*PI;
        while (radius != 0) {
            radius *= a;
            ans += radius*radius*PI;
            radius = floor(radius/b);
            ans += radius*radius*PI;
        }
        cout << "Case #" << i << ": " << ans << '\n';
    }
}