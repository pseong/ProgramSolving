#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int an[110][110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    string s;
    vector<vector<int>> v;
    for (int i=0; i<h; i++) {
        cin >> s;
        for (int j=0; j<w; j++) {
            if (s[j] == 'o') {
                v.push_back({i, j});
            }
        }
    }
    cout << abs(v[0][0] - v[1][0]) + abs(v[0][1] - v[1][1]);
}