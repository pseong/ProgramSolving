#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long a, b, k;
    cin >> a >> b >> k;

    long long ans = 0;
    while (a < b) {
        ans++;
        a *= k;
    }
    cout << ans;
}