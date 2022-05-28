#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> d(3);
    cin >> d[0] >> d[1] >> d[2];
    vector<int> d2 = d;
    sort(d.begin(), d.end());
    if (d[1] == d2[1]) cout << "Yes";
    else cout << "No";
}