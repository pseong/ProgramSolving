#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    if (n==0) {
        cout << 0;
        return 0;
    }
    int sign = 1;
    if (n < 0) {
        n = -n;
        sign = -1;
    }
    string s;
    while (n > 0) {
        s.push_back(n%3+'0');
        n /= 3;
    }

    s.push_back('0');
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '2') s[i+1]++;
        else if (s[i] == '3') {
            s[i+1]++;
            s[i] = '0';
        }
    }
    if (s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());

    if (sign == 1) {
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '2') s[i] = 'T';
        }
    }
    else {
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '2') s[i] = '1';
            else if (s[i] == '1') s[i] = 'T';
        }
    }
    cout << s;
}