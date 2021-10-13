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

int n, m, visit[1010][1010];
char an[1010][1010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> an[i][j];
        }
    }

    int mark=1;
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visit[i][j]==0) {
                int x=i;
                int y=j;
                bool nnew=false;
                while(true) {
                    if(visit[x][y]==0) {
                        visit[x][y] = mark;
                        if(an[x][y]=='U') {
                            x--;
                        }
                        else if(an[x][y]=='D') {
                            x++;
                        }
                        else if(an[x][y]=='L') {
                            y--;
                        }
                        else if(an[x][y]=='R') {
                            y++;
                        }
                    }
                    else {
                        if(visit[x][y]==mark) nnew = true;
                        break;
                    }
                }
                if(nnew) ans++;
                mark++;
            }
        }
    }
    cout << ans;
}