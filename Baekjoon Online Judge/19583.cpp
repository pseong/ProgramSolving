#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string a, b, c;
    cin >> a >> b >> c;
    string h, m;
    h.push_back(a[0]);
    h.push_back(a[1]);
    m.push_back(a[3]);
    m.push_back(a[4]);
    int start=stoi(h)*60+stoi(m);
    h.clear(); m.clear();
    h.push_back(b[0]);
    h.push_back(b[1]);
    m.push_back(b[3]);
    m.push_back(b[4]);
    int end1=stoi(h)*60+stoi(m);
    h.clear(); m.clear();
    h.push_back(c[0]);
    h.push_back(c[1]);
    m.push_back(c[3]);
    m.push_back(c[4]);
    int end2=stoi(h)*60+stoi(m);
    h.clear(); m.clear();
    string time, name;
    map<string, bool> check1;
    map<string, bool> check2;
    while(cin >> time) {
        cin >> name;
        h.push_back(time[0]);
        h.push_back(time[1]);
        m.push_back(time[3]);
        m.push_back(time[4]);
        int t=stoi(h)*60+stoi(m);
        h.clear(); m.clear();
        if(t<=start) {
            check1[name] = 1;
        }
        if(t>=end1&&t<=end2) {
            check2[name] = 1;
        }
    }
    int ans=0;
    for(auto aut : check1) {
        if(check2[aut.first]) ans++;
    }
    cout << ans;
}