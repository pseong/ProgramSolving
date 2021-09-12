#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    bool prime[1000001];
    for(int i = 0; i <= n; i++)
        prime[i] = 1;

    prime[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(prime[i] == 0) continue;
        for(int j = i * 2; j <= n; j += i)
            prime[j] = 0;
    }

    for(int i = m; i <= n; i++)
        if(prime[i]) cout << i << '\n';
}