#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        string ans="";
        queue<pair<int, string>> bfs;
        int visit[10000]{0};
        visit[a] = 1;
        bfs.push({a, ""});
        while(!bfs.empty()) {
            int n=bfs.front().first;
            string& s=bfs.front().second;
            bfs.pop();
            if(n==b) {
                ans = s;
                break;
            }
            int d1 = n%10;
            int d2 = n/10%10;
            int d3 = n/100%10;
            int d4 = n/1000%10;

            int n2;
            n2 = n*2%10000;
            if(!visit[n2]) {
                visit[n2] = 1;
                s.push_back('D');
                bfs.push({n2, s});
                s.pop_back();
            }
            n2 = ((n==0) ? 9999 : n-1);
            if(!visit[n2]) {
                visit[n2] = 1;
                s.push_back('S');
                bfs.push({n2, s});
                s.pop_back();
            }
            n2 = ((d3*10+d2)*10+d1)*10+d4;
            if(!visit[n2]) {
                visit[n2] = 1;
                s.push_back('L');
                bfs.push({n2, s});
                s.pop_back();
            }
            n2 = ((d1*10+d4)*10+d3)*10+d2;
            if(!visit[n2]) {
                visit[n2] = 1;
                s.push_back('R');
                bfs.push({n2, s});
                s.pop_back();
            }
        }
        cout << ans << '\n';
    }
}