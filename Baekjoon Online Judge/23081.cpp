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
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

int n;
char an[550][550]{0};

bool comp(tiii a, tiii b) {
    if(get<0>(a)==get<0>(b)) {
        if(get<1>(a)==get<1>(b)) {
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

int f(int i, int j) {
    int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};

    int cnt=0;
    for(int d=0; d<8; d++) {
        int x=i+dx[d];
        int y=j+dy[d];
        int res=0;
        bool flag=false;
        bool fail=false;
        while(x>=0&&x<n&&y>=0&&y<n) {
            if(an[x][y]=='W') res++;
            else if(an[x][y]=='B') {
                flag=true;
                break;
            }
            else if(an[x][y]=='.') {
                fail = true;
                break;
            }
            x += dx[d];
            y += dy[d];
        }
        if(fail) continue;
        if(flag) cnt += res;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> an[i][j];
        }
    }
    vector<tiii> v;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(an[i][j]=='.') {
                int cnt=f(i, j);
                if(cnt!=0) v.push_back({cnt, i, j});
            }
        }
    }
    if(v.size()==0) {
        cout << "PASS";
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    int cnt, i, j;
    tie(cnt, i, j) = v[0];
    cout << j << ' ' << i << '\n';
    cout << cnt;
}