#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll sum = k*(k+1)/2;
    if (n < sum) cout << -1;
    else if ((n-sum)%k == 0) cout << k-1;
    else cout << k;
}