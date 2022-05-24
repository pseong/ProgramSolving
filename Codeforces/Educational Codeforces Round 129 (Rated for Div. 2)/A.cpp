#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n;
        vector<int> an(n);
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        cin >> m;
        vector<int> bn(m);
        for (int i=0; i<m; i++) {
            cin >> bn[i];
        }
        int x = *max_element(an.begin(), an.end());
        int y = *max_element(bn.begin(), bn.end());
        if (x > y) {
            cout << "Alice\n";
            cout << "Alice\n";
            continue;
        }
        if (x < y) {
            cout << "Bob\n";
            cout << "Bob\n";
            continue;
        }
        cout << "Alice\n";
        cout << "Bob\n";
    }
}  