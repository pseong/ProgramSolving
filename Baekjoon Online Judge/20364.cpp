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

    int n, q;
    cin >> n >> q;
    map<int, int> visit;
    for(int i=1; i<=q; i++) {
        int a;
        cin >> a;
        int copy_a=a;
        int fail=false;
        int block=-1;
        while(a!=1) {
            if(visit[a]) {
                fail = true;
                block = a;
            }
            a /= 2;
        }
        if(fail) {
            cout << block << '\n';
        }
        else {
            visit[copy_a] = 1;
            cout << 0 << '\n';
        }
    }
}