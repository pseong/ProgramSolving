#include <iostream>

int sum[100010]{0};

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
    }
    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << sum[b]-sum[a-1] << '\n';
    }
}