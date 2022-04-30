#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string s;
        cin >> s;
        ll cnt = 0;
        for (int i=0; i<s.size(); i++) {
            cnt += (s[i]-'a'+1);
        }
        if (s.size() % 2 == 0) {
            cout << "Alice " << cnt << '\n';
        }
        else {
            ll a = cnt - (min(s.front(), s.back())-'a'+1);
            ll b = cnt - a;
            if (a > b) {
                cout << "Alice " << a - b;
            }
            else {
                cout << "Bob " << b - a;
            }
            cout << '\n';
        }
    }
}