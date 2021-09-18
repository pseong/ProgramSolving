#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

bool f(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool f2(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

long long broot(int start, int end) {
    long long res=40000000000;
    for(int i=start; i<end; i++) {
        for(int j=i+1; j<end; j++) {
            int a = v[j].second;
            long long r=(v[j].second-v[i].second)*(v[j].second-v[i].second)+(v[j].first-v[i].first)*(v[j].first-v[i].first);
            res = min(res, r);
        }
    }
    return res;
}

long long partition(int start, int end, long long res) {
    if(end-start<=3) return broot(start, end);
    int mid=(start+end)/2;
    long long a=partition(start, mid, res);
    long long b=partition(mid, end, res);
    res = min(a, b);
    vector<pair<int, int>> vec;
    for (int i=start; i<end; i++) {
        long long d = v[i].first - v[mid].first;
        if(d*d < res) vec.push_back(v[i]);
    }
    sort(vec.begin(), vec.end(), f2);
    int sz=vec.size();
    for(int i=0; i<sz-1; i++) {
        for(int j=i+1; j<sz; j++) {
            int a=(vec[j].second-vec[i].second);
            if((vec[j].second-vec[i].second)*(vec[j].second-vec[i].second)>res) break;
            long long r=(vec[j].second-vec[i].second)*(vec[j].second-vec[i].second)+(vec[j].first-vec[i].first)*(vec[j].first-vec[i].first);
            res = min(res, r);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    cout << partition(0, v.size(), 40000000000);
}
