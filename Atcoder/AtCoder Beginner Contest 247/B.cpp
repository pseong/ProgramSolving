#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

map<string, int> mp;
string s[110], t[110];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> t[i];
        mp[s[i]]++;

        if (s[i] != t[i]) mp[t[i]]++;
    }

    bool ans = true;
    for (int i=0; i<n; i++) {
        if (mp[s[i]]!=1 && mp[t[i]]!=1) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "Yes";
    else cout << "No";
}