#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    priority_queue<pair<int, int>> pq;
    int n;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        if(a) {
            pq.push({-abs(a), -a});
        } else {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << -pq.top().second << '\n';
                pq.pop();
            }
        }
    }
}