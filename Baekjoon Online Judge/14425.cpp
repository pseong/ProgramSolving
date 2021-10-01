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

string in;
string pattern;

struct Node{
    map<char, Node*> child;
    bool exist=false;
    void insert(int idx) {
        if(idx==in.size()) {
            exist = true;
            return;
        }
        Node* node=child[in[idx]];
        if(node==nullptr) {
            node = new Node;
            child[in[idx]] = node;
        }
        node->insert(idx+1);
    }
    bool find(int idx) {
        if(idx==pattern.size()) {
            if(exist) return 1;
            else return 0;
        }
        Node* node=child[pattern[idx]];
        if(node==nullptr) {
            return 0;
        } else {
            return node->find(idx+1);
        }
    }
};

Node trie;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> in;
        trie.insert(0);
    }

    int ans=0;
    for(int i=0; i<m; i++) {
        cin >> pattern;
        ans += trie.find(0);
    }
    cout << ans;
}