#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> ans(n, 0);
        string out;
        int rest = k;
        int one = 0;
        int zero = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') {
                one++;
            }
            else {
                zero++;
            }
        }
        if (k&1) {
            if (rest >= one) {
                for (int i=0; i<n; i++) {
                    if (s[i] == '1') {
                        rest--;
                        ans[i]++;
                    }
                    out.push_back('1');
                }
                ans[n-1] += rest;
                if (rest % 2) {
                    out.pop_back();
                    out.push_back('0');
                }
            }
            else {
                for (int i=0; i<n; i++) {
                    if (s[i] == '1') {
                        if (rest) {
                            out.push_back('1');
                            ans[i]++;
                            rest--;
                        }
                        else {
                            out.push_back('0');
                        }
                    }
                    else {
                        out.push_back('1');
                    }
                }
            }
        }
        else {
            if (rest >= zero) {
                for (int i=0; i<n; i++) {
                    if (s[i] == '0') {
                        rest--;
                        ans[i]++;
                    }
                    out.push_back('1');
                }
                ans[n-1] += rest;
                if (rest % 2) {
                    out.pop_back();
                    out.push_back('0');
                }
            }
            else {
                for (int i=0; i<n; i++) {
                    if (s[i] == '0') {
                        if (rest) {
                            out.push_back('1');
                            ans[i]++;
                            rest--;
                        }
                        else {
                            out.push_back('0');
                        }
                    }
                    else {
                        out.push_back('1');
                    }
                }
            }
        }
        cout << out << '\n';
        for (int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}