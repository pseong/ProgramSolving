#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    long long k=1;
    while(true) {
        if(n<=k*(k+1)/2) {
            break;
        }
        k++;
    }
    int a=n-(k-1)*k/2;
    int b=k+1-a;
    if(k%2==1) swap(a, b);
    cout << a << '/' << b;
}