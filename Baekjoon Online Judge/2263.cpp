#include <iostream>

int n;
int inorder[100001]{0};
int postorder[100001]{0};
int index[100001]{0};

using namespace std;

void preOrder(int inS, int inE, int postS, int postE) {
    if(inS>inE||postS>postE) return;
    int root = postorder[postE];
    cout << root << ' ';
    preOrder(inS, index[root]-1, postS, postS+index[root]-inS-1);
    preOrder(index[root]+1, inE, postS+index[root]-inS, postE-1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    for(int i=0; i<n; i++) {
        cin >> postorder[i];
    }
    for(int i=0; i<n; i++) {
        index[inorder[i]] = i;
    }
    preOrder(0, n-1, 0, n-1);
}