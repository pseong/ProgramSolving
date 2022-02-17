#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

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

bool KMP() {
    int j = 0;
    for (int i=0; i<s.size(); i++) {
        while (j>0 && s[i] != p[j]) {
            j = table[j-1];
        }
        if (s[i] == p[j]) {
            if (j == p.size()-1) 
            {
                return true;
            }
            else {
                j++;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str >> p;
    table.resize(p.size());
    for (char c : str) {
        if (c>='a' && c<='z' || c>='A' && c<='Z') {
            s.push_back(c);
        }
    }
    makeTable();
    cout << (KMP() ? 1 : 0);
}