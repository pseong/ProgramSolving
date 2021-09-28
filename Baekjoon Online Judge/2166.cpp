#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double x[10010]{0};
double y[10010]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n+1] = x[1];
    y[n+1] = y[1];

    double ans=0;
    for(int i=1; i<=n; i++) {
        ans += (x[i]*y[i+1]-x[i+1]*y[i])/2;
    }
    cout << fixed << setprecision(1) << fabs(ans);
}