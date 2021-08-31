#include <iostream>
#include <vector>

using namespace std;

int ans=0;
vector<int> a;
void func(int energy) {
    int n=a.size();
    if(n==2) {
        ans = max(ans, energy);
        return;
    }
    for(int i=1; i<n-1; i++) {
        int energy2=a[i-1]*a[i+1];
        int temp=a[i];
        a.erase(a.begin()+i);
        func(energy+energy2);
        a.insert(a.begin()+i, temp);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int c;
        cin >> c;
        a.push_back(c);
    }
    func(0);
    cout << ans;
}