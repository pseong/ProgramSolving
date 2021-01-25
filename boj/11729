#include <bits/stdc++.h>

using namespace std;

void Hanoi(int n, int from, int by, int to) {
    if(n == 1) cout << from << ' ' << to << '\n';
    else {
        Hanoi(n - 1, from, to, by);
        cout << from << ' ' << to << '\n';
        Hanoi(n - 1, by, from, to);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    Hanoi(n, 1, 2, 3);
}