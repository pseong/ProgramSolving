#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, an[1010], bn[1010];
void f(int s, int e, int s2, int e2) {
    if(e<s||e2<s2) return;
    int root=an[s];
    int idx=find(bn+s2, bn+e2, an[s])-bn;
    int cnt=idx-s2;
    f(s+1, s+cnt, s2, idx-1);
    f(s+cnt+1, e, idx+1, e2);
    cout << root << ' ';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> an[i];
        }
        for(int i=0; i<n; i++) {
            cin >> bn[i];
        }
        f(0, n-1, 0, n-1);
        cout << '\n';
    }
}