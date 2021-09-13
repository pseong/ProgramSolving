#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>*> v;

bool func(pair<int, int>* a, pair<int, int>* b) {
    if(a->first==b->first) {
        return a->second < b->second;
    }
    return a->first < b->first;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        pair<int, int>* pii = new pair<int, int>(a, -1);
        v.push_back(pii);
    }

    vector<pair<int, int>*> v2(v);
    sort(v2.begin(), v2.end(), func);

    int idx=0;
    for(int i=0; i<v2.size(); i++) {
        if(i>0&&v2[i-1]->first==v2[i]->first) idx--;
        v2[i]->second = idx;
        idx++;
    }

    for(auto aut : v) {
        cout << aut->second << ' ';
    }
}