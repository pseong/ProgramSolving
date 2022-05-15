#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    vector<int> a(m);
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            if (s[i+1][j] == 'X' && s[i][j+1] == 'X') a[j+1]++;
        }
    }
    for (int i=1; i<m; i++) {
        a[i] = a[i-1] + a[i];
    }
    int q; cin >> q;
    while (q--) {
        int x1, x2; cin >> x1 >> x2;
        x1--; x2--;
        cout << ((a[x1] == a[x2]) ? "YES\n" : "NO\n");
    }
}