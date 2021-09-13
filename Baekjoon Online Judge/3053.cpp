#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    double r;
    cin >> r;
    cout << fixed;
    cout.precision(6);
    cout << r*r*M_PI << '\n' << 2*r*r;
}