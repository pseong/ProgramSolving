#include <iostream>

using namespace std;

int an[2500][2500]{0};
int ans[3]{0};
int n;

void f(int x1, int y1, int x2,  int y2) {
    int a=-2;
    bool one=true;
    for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
            if(a==-2) a = an[i][j];
            else if(a != an[i][j]) one=false;
        }
    }
    if(one) ans[a]++;
    else {
        int gap=(x2-x1+1)/3;
        for(int i=x1; i<=x2; i+=gap) {
            for(int j=y1; j<=y2; j+=gap) {
                f(i,j,i+gap-1,j+gap-1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
            an[i][j]++;
        }
    }
    f(1,1,n,n);
    for(int i=0; i<3; i++) {
        cout << ans[i] << '\n';
    }
}
