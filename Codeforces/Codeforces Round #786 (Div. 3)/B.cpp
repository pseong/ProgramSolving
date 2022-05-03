#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> v;
    for (int i='a'; i<='z'; i++) {
        for (int j='a'; j<='z'; j++) {
            if (i==j) continue;
            string s;
            s.push_back(i);
            s.push_back(j);
            v.push_back(s);
        }
    }
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        cout << lower_bound(v.begin(), v.end(), s) - v.begin() + 1 << '\n';
    }
}