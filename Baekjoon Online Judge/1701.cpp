#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

string p, sub_p;
int table[5010];

void makeTable() {
    int j = 0;
    for (int i=1; i<sub_p.size(); i++) {
        while ((j>0 && sub_p[j] != sub_p[i])) {
            j = table[j-1];
        }
        if (sub_p[j] == sub_p[i]) {
            table[i] = ++j;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> p;
    int ans = 0;
    for (int k=0; k<p.size(); k++) {
        sub_p = p.substr(k);
        memset(table, 0, sizeof(table));
        makeTable();
        for (int i=0; i<sub_p.size(); i++) {
            ans = max(ans, table[i]);
        }
    }
    cout << ans;
}