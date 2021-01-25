#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;

    int adj[100010]{ 0 };
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            adj[i] = a;
        }

        bool visited[100010]{ 0 };
        short team[100010]{ 0 };

        for(int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            int go = i;
            while(!visited[go]) {
                visited[go] = 1;
                go = adj[go];
            }
            if(team[go] == 0) {
                while(!team[go]) {
                    team[go] = 1;
                    go = adj[go];
                }
            }
            go = i;
            while(!team[go]) {
                team[go] = 2;
                go = adj[go];
            }
        }
        
        int result = 0;
        for(int i = 1; i <= n; i++)
            if(team[i] == 2) result++;
        cout << result << '\n';
    }
}