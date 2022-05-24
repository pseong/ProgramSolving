#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll dp[303030][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    vector<int> an(n);
    for (int i=0; i<n; i++) cin >> an[i];
    bool f = (s.front() == s.back()) ? 1 : 0;

    int i = 0;
    while (i<n && s[i] == s[0]) i++;
    an.erase(an.begin(), an.begin()+i);
    s.erase(s.begin(), s.begin()+i);

    n = s.size();
    i = n-1;
    while (i>=0 && s[i] == s[n-1]) i--;
    an.erase(an.begin()+i+1, an.begin()+n);
    s.erase(s.begin()+i+1, s.begin()+n);

    n = s.size();
    int prev = 0;
    vector<int> v;
    for (int i=1; i<=n; i++) {
        if (i == n || s[i] != s[i-1]) {
            sort(an.begin()+prev, an.begin()+i);
            v.push_back(an[i-1]);
            prev = i;
        }
    }
    
    sort(v.rbegin(), v.rend());
    ll sum = 0;
    for (int i=0; i<(v.size()+1)/2; i++) {
        sum += v[i];
    }
    cout << sum;
}