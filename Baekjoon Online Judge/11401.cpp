#include <iostream>

using namespace std;

long long n, k;

long long f(long long x, long long y) {
    if(y==0) return 1;
    else if(y==1) return x%1000000007;
    if(y%2==1) return f(x, y-1)*x%1000000007;
    long long mid = f(x, y/2)%1000000007;
    return (mid*mid)%1000000007;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    if(k==0) {
        cout << 1;
        return 0;
    }
    long long a=1;
    for(int i=n; i>n-k; i--) {
        a *= i;
        a %= 1000000007;
    }

    long long b=1;
    for(int i=1; i<=k; i++) {
        b *= i;
        b %= 1000000007;
    }
    b = f(b, 1000000005);
    cout << (a * b) % 1000000007;
}