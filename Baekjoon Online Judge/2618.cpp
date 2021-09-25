#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v;
unsigned long long sum[1010]{0};
unsigned long long dp[1010][1010]{0};
int trace[1010][1010]{0};
int n, w;

int dist(int a, int b, int sel) {
    if(a==0) {
        if(sel==0) return sum[b]-sum[1]+v[1].first+v[1].second-2;
        else return sum[b]-sum[1]+n-v[1].first+n-v[1].second;
    } else {
        return sum[b]-sum[a];
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> w;
    v.push_back({1, 1});
    for(int i=0; i<w; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for(int i=1; i<=w; i++) {
        sum[i] = sum[i-1]+abs(v[i].first-v[i-1].first)+abs(v[i].second-v[i-1].second);
    }

    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=w; i++) {
        dp[i][0] = dist(0, i, 0);
        dp[0][i] = dist(0, i, 1);
    }
    for(int i=2; i<=w; i++) {
        long long a=1000000000000000;
        for(int x=0; x<=i-2; x++) {
            v[0] = {1, 1};
            if(dp[i][i-1] > dp[x][i-1]+abs(v[x].first-v[i].first)+abs(v[x].second-v[i].second)) {
                dp[i][i-1] = dp[x][i-1]+abs(v[x].first-v[i].first)+abs(v[x].second-v[i].second);
                trace[i][i-1] = x;
            }
        }
        for(int k=i+1; k<=w; k++) {
            dp[k][i-1] = dp[i][i-1] + dist(i, k, 0);
        }
        a=1000000000000000;
        for(int x=0; x<=i-2; x++) {
            v[0] = {n, n};
            if(dp[i-1][i] > dp[i-1][x]+abs(v[x].first-v[i].first)+abs(v[x].second-v[i].second)) {
                dp[i-1][i] = dp[i-1][x]+abs(v[x].first-v[i].first)+abs(v[x].second-v[i].second);
                trace[i-1][i] = x;
            }
        }
        for(int k=i+1; k<=w; k++) {
            dp[i-1][k] = dp[i-1][i] + dist(i, k, 1);
        }
    }

    long long ans=1000000000000000;
    int a, b;
    for(int i=0; i<=w-1; i++) {
        if(ans>dp[w][i]) {
            ans = dp[w][i];
            a = w;
            b = i;
        }
    }
    for(int i=0; i<=w-1; i++) {
        if(ans>dp[i][w]) {
            ans = dp[i][w];
            a = i;
            b = w;
        }
    }
    cout << ans << '\n';
    int ans2[1010]{0};
    while(!(a==0&&b==0)) {
        if(a<b) {
            for(int i=a+1; i<=b; i++) {
                ans2[i] = 2;
            }
            b = trace[a][a+1];
        } else {
            for(int i=b+1; i<=a; i++) {
                ans2[i] = 1;
            }
            a = trace[b+1][b];
        }
    }

    for(int i=1; i<=w; i++) {
        cout << ans2[i] << '\n';
    }
}