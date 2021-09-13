#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int an[1000000]{0};

int mn=1000000;
int mx=-4000;
int cnt[1000000]{0};

bool func(pair<int, int> a, pair<int, int> b) {
    if(a.first==b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    set<int> set_an;
    int sum=0;
    for(int i=0; i<n; i++) {
        cin >> an[i];
        cnt[an[i]+4000]++;
        set_an.insert(an[i]);
        sum += an[i];
        mx = max(mx, an[i]);
        mn = min(mn, an[i]);
    }
    vector<pair<int, int>> v;
    for(int zz : set_an) {
        v.push_back({cnt[zz+4000], zz});
    }
    sort(an, an+n);
    sort(v.begin(), v.end(), func);

    int cb;
    int a=v[v.size()-1].second;
    int b= v[v.size()-2].second;
    if(v.size()>1&&v[v.size()-1].first==v[v.size()-2].first) {
        cb = v[v.size()-2].second;
    } else {
        cb = v[v.size()-1].second;
    }

    cout << round(double(sum)/n) << '\n';
    cout << an[n/2] << '\n';
    cout << cb << '\n';
    cout << mx - mn;
}