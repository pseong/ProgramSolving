#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int an[1000010]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int d=c-b;
    if(d<=0) {
        cout << -1;
        return 0;
    }
    cout << a/d+1;
}