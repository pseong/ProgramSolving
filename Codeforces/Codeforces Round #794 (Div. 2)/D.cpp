#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s; cin >> s;
        int n = s.size();
        int cntA = a + c + d;
        int cntB = b + c + d;
        int incntA = 0;
        int incntB = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == 'A') incntA++;
            else incntB++;
        }
        if (!(cntA == incntA && cntB == incntB)) {
            cout << "NO\n";
            continue;
        }

        vector<int> chk(n);
        for (int i=1; i<n; i++) {
            if (s[i-1] == s[i] && s[i] == s[i+1]) {
                chk[i] = 1;
                if (s[i] == 'A') {
                    a--;
                }
                else {
                    b--;
                }
            }
        }
        if (a < 0 || b < 0) {
            cout << "NO\n";
            continue;
        }
        string s2;
        for (int i=0; i<n; i++) {
            if (!chk[i]) s2.push_back(s[i]);
        }
        s = s2;
        n = s.size();
        
        if (s.size() > 1) {
            if (s[0] == s[1]) {
                if (s[0] == 'A') {
                    a--;
                }
                else b--;
                s.erase(s.begin());
            }
        }
        n = s.size();

        if (s.size() > 1) {
            if (s[n-2] == s[n-1]) {
                if (s.back() == 'A') {
                    a--;
                }
                else b--;
                s.pop_back();
            }
        }
        n = s.size();

        if (a < 0 || b < 0) {
            cout << "NO\n";
            continue;
        }

        vector<int> evenA;
        vector<int> evenB;
        int x = 0;
        int cnt = 0;
        for (int i=0; i<=n; i++) {
            if (i == n || i != 0 && s[i-1] == s[i]) {
                if (cnt%2 == 0) {
                    if (s[i-1] == 'A') evenB.push_back(cnt);
                    else evenA.push_back(cnt);
                }
                else x += cnt/2;
                cnt = 0;
            }
            cnt++;
        }
        sort(evenA.rbegin(), evenA.rend());
        sort(evenB.rbegin(), evenB.rend());
        for (int i=(int) evenA.size()-1; i>=0; i--) {
            if (c >= evenA[i]/2) {
                c -= evenA[i]/2;
            }
            else {
                x += (evenA[i]-1)/2;
            }
        }
        for (int i=(int) evenB.size()-1; i>=0; i--) {
            if (d >= evenB[i]/2) {
                d -= evenB[i]/2;
            }
            else {
                x += (evenB[i]-1)/2;
            }
        }
        if (c + d <= x) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}