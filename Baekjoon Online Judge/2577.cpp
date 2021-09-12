#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int a, b ,c;
    cin >> a >> b >> c;
    long long mul = a * b * c;

    int res[10]{ 0 };
    for(int i = 10;;i *= 10) {
        res[(mul%i)*10/i]++;
        if(mul%i == mul) break;
    }

    for(int i = 0; i < 10; i++) {
        cout << res[i] << '\n';
    }
}