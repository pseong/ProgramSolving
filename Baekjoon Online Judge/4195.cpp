#include <iostream>
#include <map>

using namespace std;

map<string, string> parent;
map<string, int> cnt;

string getParent(string a) {
    if(parent[a]==a) return a;
    return parent[a] = getParent(parent[a]);
}

int unionParent(string a, string b) {
    a = getParent(a);
    b = getParent(b);
    if(a>b) {
        parent[a] = b;
        return cnt[b] += cnt[a];
    }
    else if(a<b) {
        parent[b] = a;
        return cnt[a] += cnt[b];
    } else {
        return cnt[a];
    }
}

int findParent(string a, string b) {
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int f;
        cin >> f;
        while(f--) {
            string s1, s2;
            cin >> s1 >> s2;
            if(parent[s1]=="") {
                parent[s1] = s1;
                cnt[s1] = 1;
            }
            if(parent[s2]=="") {
                parent[s2] = s2;
                cnt[s2] = 1;
            }
            cout << unionParent(s1, s2) << '\n';
        }
        parent.clear();
        cnt.clear();
    }
}