#include <iostream>

using namespace std;

long long a, b, c;

long long f(long long x, long long y) {
    if(y==0) return 1;
    else if(y==1) return x;
    if(y%2==1) return f(x, y-1)*x;
    long long mid = f(x, y/2)%c;
    return (mid*mid)%c;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    cout << f(a, b)%c;
}