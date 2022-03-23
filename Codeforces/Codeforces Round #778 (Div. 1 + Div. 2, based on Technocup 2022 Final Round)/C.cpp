#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll an[202020];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll sum = 0;
        priority_queue<ll> pq;
        for (int i=1; i<=n; i++) {
            cin >> an[i];
            sum += an[i];
        }
        sort(an+1, an+n+1);
        pq.push(sum);

        int cur = n;
        bool good = true;
        while (!pq.empty()) {
            if (cur==0) {
                good = false;
                break;
            }
            ll t = pq.top(); pq.pop();
            if (an[cur] < t) {
                if (t&1) {
                    pq.push(t/2);
                    pq.push(t/2+1);
                }
                else {
                    pq.push(t/2);
                    pq.push(t/2);
                }
            }
            else if(an[cur] == t) cur--;
            else {
                good = false;
                break;
            }
        }
        if (cur != 0) good = false;

        if (good) cout << "YES\n";
        else cout << "NO\n";
    }
}