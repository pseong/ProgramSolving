#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, k;
vector<int> p[2], s[110];
vector<int> table[2];

void makeTable() {
    for (int m=0; m<2; m++) {
        int j = 0;
        for (int i=1; i<p[m].size(); i++) {
            while (j>0 && p[m][j] != p[m][i]) {
                j = table[m][j-1];
            }
            if (p[m][j] == p[m][i]) {
                table[m][i] = ++j;
            }
        }
    }
}

bool _KMP(vector<int>& ss, int idx) {
    int j = 0;
    for (int i=0; i<ss.size(); i++) {
        while (j>0 && ss[i] != p[idx][j]) {
            j = table[idx][j-1];
        }
        if (ss[i] == p[idx][j]) {
            if (j == k-1) {
                return true;
                cout << "true";
            }
            else {
                j++;
            }
        }
    }
    return false;
}

bool KMP() {
    for (int i=1; i<n; i++) {
        if (!(_KMP(s[i], 0) || _KMP(s[i], 1))) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=0; i<2; i++) {
        p[i].resize(k);
        table[i].resize(k);
    }
    for (int i=0; i<n; i++) {
        int sz;
        cin >> sz;
        for (int j=0; j<sz; j++) {
            int a;
            cin >> a;
            s[i].push_back(a);
        }
    }
    for (int i=0; i<=s[0].size()-k; i++) {
        for (int j=0; j<k; j++) {
            p[0][j] = s[0][i+j];
        }

        p[1] = p[0];
        reverse(p[1].begin(), p[1].end());
        makeTable();

        if (KMP()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}