#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[500001]{ 0 };
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    int x[500001]{ 0 };
    int m;
    cin >> m;

    for(int i = 1; i <= m; i++) cin >> x[i];

    for(int i = 1; i <= m; i++) {
        int left = 1;
        int right = n;
        bool find = 0;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if (x[i] > a[mid]) {
                left = mid + 1;
            } else if (x[i] < a[mid]) {
                right = mid - 1;
            } else {
                find = 1;
                break;
            }
        }
        cout << (find ? 1 : 0) << ' ';
    }
}