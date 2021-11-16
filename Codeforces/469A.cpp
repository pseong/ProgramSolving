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

    int n;
    cin >> n;
    int an[110]{0};
    int p;
    cin >> p;
    for(int i=0; i<p; i++) {
        int a;
        cin >> a;
        an[a] = 1;
    }
    cin >> p;
    for(int i=0; i<p; i++) {
        int a;
        cin >> a;
        an[a] = 1;
    }
    bool fail=false;
    for(int i=1; i<=n; i++) {
        if(an[i]==0) fail = true;
    }
    if(fail) cout << "Oh, my keyboard!";
    else cout << "I become the guy.";
}