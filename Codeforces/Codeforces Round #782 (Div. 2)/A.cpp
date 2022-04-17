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

    int T;
    cin >> T;
    while(T--) {
        int n, r, b;
        cin >> n >> r >> b;
        int get = r / (b+1);
        int rest = r % (b+1);
        string ans;
        int cnt = 0;
        for (int i=0; i<b; i++) {
            cout << string(get, 'R');
            if (rest) {
                rest--;
                cout << 'R';
            }
            cout << 'B';
        }
        cout << string(get, 'R');
        cout << ans << '\n';
    }
}