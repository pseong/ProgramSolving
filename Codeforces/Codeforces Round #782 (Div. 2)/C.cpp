#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int an[202020];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll sum = 0;
        for (int i=0; i<n; i++) {
            cin >> an[i];
            sum += an[i];
        }
        ll cost = sum * b;
        ll cnt = n-1;
        while (cnt) {
            ll cost2 = cost;
            ll go = n - cnt - 1;
            ll gap = (go != 0) ? an[go] - an[go-1] : an[go];
            cost2 -= gap * b * cnt;
            cost2 += gap * a;
            if (cost2 < cost) {
                cost = cost2;
            }
            else {
                break;
            }
            cnt--;
        }
        cout << cost << '\n';
    }
}