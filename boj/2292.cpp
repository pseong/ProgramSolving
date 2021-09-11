#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    long long k=1;
    while(true) {
        if(n<3L*k*(k+1)+2L) {
            break;
        }
        k++;
    }
    cout << k+1;
}