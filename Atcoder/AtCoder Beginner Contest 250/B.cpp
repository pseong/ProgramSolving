#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    int color = 1;
    for (int i=0; i<n; i++) {
        int c = color;
        for (int I=0; I<a; I++) {
            for (int j=0; j<n; j++) {
                for (int J=0; J<b; J++) {
                    if (c) cout << '.';
                    else cout << '#';
                }
                c ^= 1;
            }
            if (n%2 == 1) c ^= 1;
            cout << '\n';
        }
        color ^= 1;
    }
}