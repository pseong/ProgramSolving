#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int two = 0;
    int five = 0;

    for(int j = 1; j <= n; j++) {
        int a = j;
        while(a % 2 == 0) {
            a /= 2;
            two++;
        }
        while(a % 5 == 0) {
            a /= 5;
            five++;
        }
    }
    cout << min(two, five);
}