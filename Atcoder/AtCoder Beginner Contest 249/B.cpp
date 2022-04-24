#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    bool lo = false;
    bool up = false;

    int cnt[300]{ 0 };
    for (int i=0; i<s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') lo = true;
        if (s[i] >= 'A' && s[i] <= 'Z') up = true;
        cnt[s[i]]++;
        if (cnt[s[i]] > 1) {
            cout << "No\n";
            return 0;
        }
    }
    if (lo && up) cout << "Yes\n";
    else cout << "No\n";
}