#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> v { -1 };
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'W') v.push_back(i);
        }
        v.push_back(s.size());
        bool ok = true;
        for (int i=1; i<v.size(); i++) {
            if (v[i]-v[i-1] == 1) continue;
            bool o = true;
            for (int k=v[i-1]+2; k<=v[i]-1; k++) {
                if (s[k] != s[k-1]) o = false;
            }
            if (o) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}