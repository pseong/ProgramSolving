#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=10000;
int n, an[N+10];
vector<int> v;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        v.clear();
        for(int i=1; i<=n; i++) {
            cin >> an[i];
            if(an[i]==1) v.push_back(i);
        }
        if(v.size()==0) {
            for(int i=1; i<=n+1; i++) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }
        if(v[0]!=1) {
            for(int i=1; i<v[0]; i++) {
                cout << i << ' ';
            }
            cout << n+1 << ' ';
            for(int i=v[0]; i<=n; i++) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }
        cout << n+1 << ' ';
        for(int i=1; i<=n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}