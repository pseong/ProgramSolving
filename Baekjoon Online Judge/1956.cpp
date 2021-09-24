#include <iostream>
#include <vector>

using namespace std;

vector<int> hit[401];
long long an[401][401]{0};
int v, e;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> v >> e;
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            an[i][j] = 1000000000;
            if(i==j) an[i][j] = 0;
        }
    }
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        hit[b].push_back(a);
        if(an[a][b] > c) an[a][b] = c;
    }

    for(int k=1; k<=v; k++) {
        for(int i=1; i<=v; i++) {
            for(int j=1; j<=v; j++) {
                if(an[i][j] > an[i][k]+an[k][j])
                    an[i][j] = an[i][k]+an[k][j];
            }
        }
    }

    long long ans=1000000000;
    for(int i=1; i<=v; i++) {
        for(int j : hit[i]) {
            long long dist=an[i][j]+an[j][i];
            ans = min(ans, dist);
        }
    }
    if(ans==1000000000) cout << -1;
    else cout << ans;
}