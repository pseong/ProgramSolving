#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int MX=1500000 + 10;
int cal[2][MX];

void preprocess(string& s, int cur) {
    ll cnt=0;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='(') {
            cnt += 1;
        }
        else {
            cnt -= 1;
            if (i>0 && s[i-1]=='(') {
                cal[cur][cnt]++;
            }
        }
    }
    for (int i=0; i<MX-1; i++) {
        if(cal[cur][i] >= 2) {
            cal[cur][i+1] += cal[cur][i]/2;
            cal[cur][i] %= 2;
        }
    }
}

char comp() {
    for (int i=MX-1; i>=0; i--) {
        if (cal[0][i] > cal[1][i]) return '>';
        else if (cal[0][i] < cal[1][i]) return '<';
    }
    return '=';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(cal, 0, sizeof(cal));
        string s1, s2;
        cin >> s1 >> s2;
        preprocess(s1, 0);
        preprocess(s2, 1);
        cout << comp() << '\n';
    }
}