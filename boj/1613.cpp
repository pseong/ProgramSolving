#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
    long long r;
	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int a[110] { 0 };
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        long long result = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                result += (gcd(a[i], a[j]));
            }
        }
        cout << result << '\n';
    }
}