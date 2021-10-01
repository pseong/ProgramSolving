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

vector<string> str;

struct Node{
    map<char, Node*> child;
    bool end=false;
    void insert(int idx) {
        if(idx==str[str.size()-1].size()) {
            end = true;
            return;
        }
        Node* node=child[str[str.size()-1][idx]];
        if(node==nullptr) {
            node = new Node;
            child[str[str.size()-1][idx]] = node;
        }
        node->insert(idx+1);
    }
    int find(int idx, int cnt, int str_idx) {
        if(idx==str[str_idx].size()) return cnt;
        Node* node=child[str[str_idx][idx]];
        int param=cnt+1;
        /*
        int a=child.size();
        
        char j;
        for(auto i : child) {
            j = i.first;
        }*/
        if(idx!=0 && child.size()==1 && !end) param = cnt;
        return node->find(idx+1, param, str_idx);
    }
};

Node* trie;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    while(cin>>n) {
        trie = new Node;
        string s;
        for(int i=0; i<n; i++) {
            cin >> s;
            str.push_back(s);
            trie->insert(0);
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            ans += trie->find(0, 0, i);
        }
        cout << fixed << setprecision(2) << (double)ans / n << '\n';
        str.clear();
    }
}