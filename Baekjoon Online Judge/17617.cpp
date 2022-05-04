#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int v[2020202], in[1010101];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, m;
    cin >> n >> r >> m;
    for (int i=0; i<n; i++) {
        cin >> in[i];
    }
    sort(in, in+n);
    in[n] = in[0] + m;
    for (int i=1; i<=n; i++) {
        v[i] = v[i+n] = in[i]-in[i-1]-2*r;
    }

    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum += v[i];
        if (sum < 0) sum = 0;
        ans = max(ans, v[i]);
    }
    cout << (ans+1)/2;
}