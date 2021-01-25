#include <bits/stdc++.h>

using namespace std;

bool cmp(const tuple<string, int, int , int>& t1, const tuple<string, int, int , int>& t2) {
    if(get<1>(t1) == get<1>(t2)) {
        if(get<2>(t1) == get<2>(t2)) {
            if(get<3>(t1) == get<3>(t2)) {
                return get<0>(t1) < get<0>(t2);
            }
            return get<3>(t1) > get<3>(t2);
        }
        return get<2>(t1) < get<2>(t2);
    }
    return get<1>(t1) > get<1>(t2);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    vector<tuple<string, int, int , int>> v;

    int n;
    cin >> n;
    while(n--) {
        string e;
        int k, y, s;
        cin >> e >> k >> y >> s;
        v.push_back({e, k, y, s});
    }

    sort(v.begin(), v.end(), cmp);

    for(const tuple<string, int, int , int>& t : v)
        cout << get<0>(t) << '\n';
}