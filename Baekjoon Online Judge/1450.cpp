#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
int an[100]{0};

vector<long long> v[2];
void ser(long long sum, int s, int e, int cas) {
    if(s>e) return;
    ser(sum, s+1, e, cas);
    sum += an[s];
    if(sum<=c) v[cas].push_back(sum);
    else return;
    ser(sum, s+1, e, cas);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> n >> c;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
    }
    ser(0, 1, n/2, 0);
    ser(0, n/2+1, n, 1);

    long long ans=v[0].size()+v[1].size();
    sort(v[1].begin(), v[1].end());
    sort(v[0].begin(), v[0].end());

    for(int i=0; i<v[0].size(); i++) {
        ans += upper_bound(v[1].begin(), v[1].end(), c-v[0][i])-v[1].begin();
    }
    ans++;
    cout << ans;
}