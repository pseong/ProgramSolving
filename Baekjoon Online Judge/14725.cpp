#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int n;
map<string, string> mp;
vector<string> v;
struct Node{
    map<string, Node*> child;
    void insert(int idx) {
        if(idx==v.size()) return;
        Node* node = child[v[idx]];
        if(node==nullptr) {
            node = new Node;
            child[v[idx]] = node;
        }
        node->insert(idx+1);
    }
    void print(int idx) {
        for(auto it=child.begin(); it!=child.end(); it++) {
            for(int i=0; i<idx*2; i++) {
                cout << '-';
            }
            cout << it->first << '\n';
            it->second->print(idx+1);
        }
    }
};

Node root;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int cnt;
        cin >> cnt;
        for(int j=0; j<cnt; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        root.insert(0);
        v.clear();
    }
    root.print(0);
}