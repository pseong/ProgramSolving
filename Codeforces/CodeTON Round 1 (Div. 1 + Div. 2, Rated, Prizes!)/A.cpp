#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int an[202020];
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        cout << (max_element(an, an+n) - an + 1) << ' '
                << (min_element(an, an+n) - an + 1) << '\n';
    }
}