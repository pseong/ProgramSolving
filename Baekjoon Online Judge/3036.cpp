#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while(b!=0) {
        a = a%b;
        swap(a, b);
    }
    return a;
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int a;
    cin >> a;
    int an[150]{0};
    for(int i=0; i<n-1; i++) {
        cin >> an[i];
        int g=gcd(a, an[i]);
        cout << a/g << '/' << an[i]/g << '\n';
    }
}