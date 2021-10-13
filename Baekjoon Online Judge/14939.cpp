#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <list>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int copy_an[10][10];
int an[10][10];
int visit[10][10];
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};

void toggle(int i, int j) {
    an[i][j] ^= 1;
    for(int d=0; d<4; d++) {
        int x=i+dx[d];
        int y=j+dy[d];
        if(x<0||x>=10||y<0||y>=10) continue;
        an[x][y] ^= 1;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            char a;
            cin >> a;
            if(a=='O') copy_an[i][j] = 1;
            else copy_an[i][j] = 0;
        }
    }

    int ans=1000000000;
    for(int i=0; i<(1<<10); i++) {
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                an[i][j] = copy_an[i][j];
            }
        }

        int res=0;
        for(int k=0; k<10; k++) {
            if(i&(1<<k)) {
                toggle(0, k);
                res++;
            }
        }

        for(int x=1; x<10; x++) {
            for(int y=0; y<10; y++) {
                if(an[x-1][y]==1) {
                    toggle(x, y);
                    res++;
                }
            }
        }

        bool clear=true;
        for(int x=1; x<10; x++) {
            for(int y=0; y<10; y++) {
                if(an[x][y]==1) {
                    clear = false;
                }
            }
        }

        if(clear) {
            ans = min(ans, res);
        }
    }
    if(ans==1000000000) cout << -1;
    else cout << ans;
}