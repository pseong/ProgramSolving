#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool bb[101010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for (int i=1; i<=100000; i++) {
        int mul = 1;
        int sum = 0;
        int t = i;
        while (t>0) {
            mul *= t%10;
            sum += t%10;
            t /= 10;
        }
        if (mul % sum == 0) {
            bb[i] = 1;
        }
    }
    int T; cin >> T;
    for (int i=1; i<=T; i++) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i=a; i<=b; i++) {
            ans += bb[i];
        }
        cout << "Case #" << i << ": " << ans << '\n';
    }
}