#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int card[20000001]{ 0 };

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        card[a + 10000000]++;
    }

    int m;
    cin >> m;

    for(int i = 1; i <= m; i++) {
        int find = 0;
        cin >> find;
        cout << card[find + 10000000] << ' ';
    }
}