#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int an[101010]{ 0 };
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> an[i];
    }
    unsigned long long now = 0;
    for (int i=0; i<n; i++) {
        unsigned long long m = (1LL << an[i]);
        unsigned long long mask = (now >> an[i]);
        mask++;
        mask <<= an[i];
        for (int k=an[i]+1; k<64; k++) {
            if (mask & (1LL << k)) {
                m |= (1LL << k);
            }
        }
        now = m;
    }
    cout << now;
}