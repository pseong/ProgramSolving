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
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<long long, long long, long long>;

char an[110][110]{0};
int t, n, m;
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};
int gett[110][110]{0};
int item[30]{0};
int cnt=0;
int visit[110][110]{0};

bool bfs(int i, int j) {
    if (visit[i][j]==1) return true;
    if (an[i][j]=='*') return true;
    queue<pii> q;
    if(i==0) q.push({i-1, j});
    else if(j==0) q.push({i, j-1});
    else if(i==n-1) q.push({i+1, j});
    else if(j==m-1) q.push({i, j+1});
    while(!q.empty()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        for(int d=0; d<4; d++) {
            int x=a+dx[d];
            int y=b+dy[d];
            if(x<0||x>=n||y<0||y>=m) continue;
            if(visit[x][y]) continue;
            visit[x][y] = 1;
            if(an[x][y]=='*') continue;
            if(an[x][y]>='A' && an[x][y]<='Z') {
                int gap='a'-'A';
                if(!item[an[x][y]+gap-'a']) continue;
                q.push({x, y});
            }
            else if(an[x][y]=='$') {
                q.push({x, y});
                if(!gett[x][y]) {
                    gett[x][y] = 1;
                    cnt++;
                }
            }
            else if(an[x][y]>='a' && an[x][y]<='z') {
                q.push({x, y});
                if(!item[an[x][y]-'a']) {
                    item[an[x][y]-'a'] = 1;
                    return false;
                }
            }
            else if(an[x][y]=='.') {
                q.push({x, y});
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> an[i][j];
            }
        }
        string s;
        getline(cin, s);
        getline(cin, s);
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='0') break;
            item[s[i]-'a'] = true;
        }
        while(true) {
            memset(visit, 0, sizeof(visit));
            bool fail=false;
            for(int i=0; i<n; i++) {
                int j=0;
                bool ret;
                ret = bfs(i, j);
                if(!ret) {
                    fail = true;
                    break;
                }
                j = m-1;
                ret = bfs(i, j);
                if(!ret) {
                    fail = true;
                    break;
                }
            }
            if(fail) continue;

            for(int j=0; j<m; j++) {
                int i=0;
                bool ret;
                ret = bfs(i, j);
                if(!ret) {
                    fail = true;
                    break;
                }
                i = n-1;
                ret = bfs(i, j);
                if(!ret) {
                    fail = true;
                    break;
                }
            }
            if(fail) continue;
            break;
        }
        cout << cnt << '\n';
        memset(item, 0, sizeof(item));
        memset(gett, 0, sizeof(gett));
        cnt = 0;
    }
}