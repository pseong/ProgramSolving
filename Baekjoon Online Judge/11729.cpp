#include <iostream>

using namespace std;

void f2(int n, int from, int to, int by) {
    if(n==1) cout << from << ' ' << to << '\n';
    else {
        f2(n-1, from, by, to);
        cout << from << ' ' << to << '\n';
        f2(n-1, by, to, from);
    }
}

int f(int n, int from, int to, int by) {
    if(n==1) return 1;
    return f(n-1, from, by, to)+1+f(n-1, by, from, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << f(n, 1, 3, 2) << '\n';
    f2(n, 1, 3, 2);
}