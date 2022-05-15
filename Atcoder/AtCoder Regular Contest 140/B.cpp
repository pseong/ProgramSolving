#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; string s;
    cin >> n >> s;
    int sum = 0;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'R') {
            int l = i-1;
            int r = i+1;
            int x = 0;
            while (l >= 0 && r < n) {
                if (s[l] == 'A' && s[r] == 'C') x++;
                else break;
                l--; r++;
            }
            if (x == 0) continue;
            sum += x;
            cnt++;
        }
    }
    cout << min(sum, cnt * 2);
}