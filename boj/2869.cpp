#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    long long a, b, v;
    cin >> a >> b >> v;

    long long av=a-b;
    long long high=a;
    if(high>v) {
        cout << 0;
        return 0;
    }
    v -= a;
    double db=(double)v/av;
    long long day=ceil((double)v/av);
    cout << day;
}