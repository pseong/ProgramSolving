#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    for(int k = 1; k <= n - 1; k++)
        cout << ' ';
    cout << '*' << '\n';

    if(n == 1) return 0;

    for(int i = 2; i < n; i++) {
        for(int k = 1; k <= n - i; k++)
            cout << ' ';
        cout << '*';
        for(int j = 1; j <= 2 * i - 3; j++)
            cout << ' ';
        cout << '*' << '\n';
    }
    for(int i = 1; i <= 2 * n - 1; i++)
        cout << '*';
}