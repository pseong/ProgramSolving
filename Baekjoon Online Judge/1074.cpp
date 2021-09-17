#include <iostream>
#include <cmath>

using namespace std;
int n;
int r, c;
long long ans=0;
void f(int x1, int y1, int x2, int y2) {
    int gap=x2-x1+1;
    int a=1;
    if(r>x1+gap/2-1) {
        ans += gap*gap/2;
        a += 2;
    }
    if(c>y1+gap/2-1) {
        ans += gap*gap/4;
        a += 1;
    }
    if(gap==2) return;
    if(a==1) f(x1, y1, x1+gap/2-1, y1+gap/2-1);
    else if(a==2) f(x1, y1+gap/2, x1+gap/2-1, y2);
    else if(a==3) f(x1+gap/2, y1, x2, y1+gap/2-1);
    else if(a==4) f(x1+gap/2, y1+gap/2, x2, y2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> r >> c;
    r++;
    c++;
    n = pow(2, n);
    f(1, 1, n, n);
    cout << ans;
}