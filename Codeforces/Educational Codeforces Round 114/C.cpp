#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int a[300]{0};
    int sum=0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a+1, a+n+1);
    int m;
    cin >> m;
    int x[300]{0}; // 방어력
    int y[300]{0}; // 공격력
    for(int i=1; i<=m; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i=1; i<=m; i++) {
        int s=sum;
        int ans=0;
        int idx=lower_bound(a+1, a+n+1, x[i])-a;
        if(idx>=n) {
            idx--;
            ans += x[i]-a[idx];
            s -= a[idx];
            if(s < y[i]) {
                ans += y[i] - s;
            }
            cout << ans << '\n';
            continue;
        } else {
            s -= a[idx];
            if(s>=y[i]) {
                cout << ans << '\n';
                continue;
            } else {
                int ab=y[i]-s;
                if(idx==1) {
                    cout << ab << '\n';
                    continue;
                }
                s += a[idx];
                idx--;
                int b=0;
                if(a[idx] < x[i]) {
                    b += x[i]-a[idx];
                }
                s -= a[idx];
                if(s<y[i]) {
                    b += y[i]-s;
                }
                cout << min(ab, b) << '\n';
            }
        }
    }
}