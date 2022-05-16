#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> sum(n+1, vector<int>(26, 0));
    for (int i=0; i<n; i++) {
        sum[i+1][s[i]-'a'] = 1;
        for (int j=0; j<26; j++) {
            sum[i+1][j] += sum[i][j];
        }
    }
    int q; cin >> q;
    for (int i=0; i<q; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        l++; r++;
        cout << sum[r][c-'a'] - sum[l-1][c-'a'] << '\n';
    }
}