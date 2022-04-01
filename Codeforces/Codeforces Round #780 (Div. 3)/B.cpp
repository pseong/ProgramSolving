#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int an[202020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        if (n==1 && an[0]>=2) {
            cout << "NO\n";
            continue;
        }
        sort(an, an+n);
        reverse(an, an+n);
        if (an[0]-an[1] > 1) {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }
}