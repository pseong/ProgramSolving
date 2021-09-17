#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v[100000];

void merge(int left, int right) {
    if(left>=right) return;
    int mid=(left+right)/2;
    if(left-mid!=0) merge(left, mid);
    if(right-mid-1!=0) merge(mid+1, right);
    vector<pair<int, int>> a;
    int i=0;
    int j=0;
    int hi=0;
    int hj=0;
    while(true) {
        if(v[left].size()>i&&v[mid+1].size()>j) {
            if(v[left][i].first<v[mid+1][j].first) {
                if(a.empty()||!a.empty()&&a.back().second!=max(v[left][i].second, hj)) {
                    a.push_back({v[left][i].first, max(v[left][i].second, hj)});
                }
                hi=v[left][i].second;
                i++;
            } else if(v[left][i].first==v[mid+1][j].first) {
                if(a.empty()||!a.empty()&&a.back().second!=max(v[mid+1][j].second, v[left][i].second)) {
                    a.push_back({v[mid+1][j].first, max(v[mid+1][j].second, v[left][i].second)});
                }
                i++;
                j++;
            } else {
                if(a.empty()||!a.empty()&&a.back().second!=max(v[mid+1][j].second, hi)) {
                    a.push_back({v[mid+1][j].first, max(v[mid+1][j].second, hi)});
                }
                hj=v[mid+1][j].second;
                j++;
            }
        } else {
            while(v[left].size()>i) {
                a.push_back(v[left][i]);
                i++;
            }
            while(v[mid+1].size()>j) {
                a.push_back(v[mid+1][j]);
                j++;
            }
            v[left] = a;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i].push_back({a, b});
        v[i].push_back({c, 0});
    }
    merge(0, n-1);
    for(auto& a : v[0]) {
        cout << a.first << ' ' << a.second << ' ';
    }
}