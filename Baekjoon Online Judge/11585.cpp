#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n;
string p, s;
vector<int> table;

void makeTable() {
    int j = 0;
    for (int i=1; i<p.size(); i++) {
        while (j>0 && p[j] != p[i]) {
            j = table[j-1];
        }
        if (p[j] == p[i]) {
            table[i] = ++j;
        }
    }
}

int KMP() {
    int j = 0;
    int ret = 0;
    for (int i=0; i<s.size(); i++) {
        while (j>0 && s[i] != p[j]) {
            j = table[j-1];
        }
        if (s[i] == p[j]) {
            if (j == p.size()-1) {
                ret++;
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        p.push_back(c);
    }
    s += s.substr(0, s.size()-1);
    table.resize(p.size(), 0);
    makeTable();
    int kmp = KMP();
    int gcd = __gcd(kmp, n);
    cout << kmp/gcd << '/' << n/gcd;
}