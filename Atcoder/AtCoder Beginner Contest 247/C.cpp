#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<vector<int>> arr(17, vector<int>());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    arr[1].push_back(1);
    for (int i=2; i<=n; i++) {
        arr[i].insert(arr[i].end(), arr[i-1].begin(), arr[i-1].end());
        arr[i].push_back(i);
        arr[i].insert(arr[i].end(), arr[i-1].begin(), arr[i-1].end());
    }
    
    for (int i : arr[n]) {
        cout << i << ' ';
    }
}