#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, m, parent[1010], cnt[1010];
map<string, int> num;
map<int, string> str;
vector<int> v[1010];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        num[s] = i;
        str[i] = s;
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        v[num[s2]].push_back(num[s1]);
        cnt[num[s1]]++;
    }
    vector<int> root;
    vector<string> root_str;
    for(int i=1; i<=n; i++) {
        if(cnt[i]==0) {
            root.push_back(i);
            root_str.push_back(str[i]);
        }
    }
    sort(root_str.begin(), root_str.end());
    cout << root.size() << '\n';
    for(int i=0; i<root_str.size(); i++) {
        cout << root_str[i] << ' ';
    }
    cout << '\n';

    map<string, vector<string>> child;
    for(int i=0; i<root.size(); i++) {
        queue<int> q;
        q.push(root[i]);
        while(!q.empty()) {
            int a=q.front();
            q.pop();
            for(int k : v[a]) {
                cnt[k]--;
                if(cnt[k]==0) {
                    q.push(k);
                    child[str[a]].push_back(str[k]);
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(child[str[i]].size()==0) {
            child[str[i]].push_back("0");
            child[str[i]].pop_back();
        }
    }
    for(auto a : child) {
        sort(a.second.begin(), a.second.end());
        cout << a.first << ' ' << a.second.size() << ' ';
        for(string& s : a.second) {
            cout << s << ' ';
        }
        cout << '\n';
    }
}