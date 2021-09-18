#include <iostream>

using namespace std;

int an[200][200]{0};

int ans[2]{0};
void f(int x1, int y1, int x2, int y2) {
    int res=-1;
    for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
            if(res==-1) res = an[i][j];
            else if(res!=an[i][j]) {
                res = -2;
                break;
            }
        }
        if(res==-2) break;
    }
    if(res!=-2) {
        ans[res]++;
    } else {
        int half=(x2-x1+1)/2;
        f(x1,y1,x2-half,y2-half);
        f(x1,y1+half,x2-half,y2);
        f(x1+half,y1,x2,y2-half);
        f(x1+half,y1+half,x2,y2);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> an[i][j];
        }
    }
    f(1,1,n,n);
    cout << ans[0] << '\n' << ans[1];
}
