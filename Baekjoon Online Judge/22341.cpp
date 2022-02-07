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

    int N, C, A, B;
    cin >> N >> C;
    A = B = N;

    while (C--) {
        int x, y;
        cin >> x >> y;
        if (x>A || y>B) continue;
        int ho=x*B;
        int ve=A*y;
        if(ho >= ve) {
            A = x;
        }
        else {
            B = y;
        }
    }
    cout << A*B;
}