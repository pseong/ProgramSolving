#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        int cnt1[18]{ 0 };
        int cnt0[18]{ 0 };
        for (int i=0; i<=r; i++) {
            int a;
            cin >> a;
            for (int i=0; i<=17; i++) {
                if (a & (1<<i)) cnt1[i]++;
                else cnt0[i]++;
            }
        }
        int x = 0;
        for (int i=0; i<=17; i++) {
            if (cnt1[i] > cnt0[i]) {
                x |= (1<<i);
            }
        }
        cout << x << '\n';
    }
}