#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool is_pal(int min) {
    int HH = min / 60;
    int MM = min % 60;
    if (HH/10 == MM%10 && HH%10 == MM/10) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string clock; cin >> clock;
        int x; cin >> x;
        int min = 0;
        min += (clock[0]-'0') * 600;
        min += (clock[1]-'0') * 60;
        min += (clock[3]-'0') * 10;
        min += (clock[4]-'0') * 1;
        vector<int> chk(1440);

        int ans = 0;
        chk[min] = 1;
        if (is_pal(min)) ans++;
        while (true) {
            min += x;
            min %= 1440;
            if (chk[min]) break;
            chk[min] = 1;
            if (is_pal(min)) ans++;
        }
        cout << ans << '\n';
    }
}