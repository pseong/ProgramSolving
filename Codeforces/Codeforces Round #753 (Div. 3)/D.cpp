#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=200000;
int n;
int an[N+10], ans[N+10];
string s;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        
        vector<int> b;
        vector<int> r;
        cin >> s;
        for(int i=1; i<=n; i++) {
            if(s[i-1]=='B') {
                b.push_back(an[i]);
            }
            else {
                r.push_back(an[i]);
            }
        }
        sort(b.begin(), b.end());
        sort(r.begin(), r.end(), greater<int>());

        bool fail=false;
        int idx=1;
        for(int i=0; i<b.size(); i++) {
            if(b[i]<idx) {
                fail = true;
                break;
            }
            idx++;
        }
        if(fail) {
            cout << "NO\n";
            continue;
        }

        fail = false;
        idx = n;
        for(int i=0; i<r.size(); i++) {
            if(r[i]>idx) {
                fail = true;
                break;
            }
            idx--;
        }
        if(fail) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}