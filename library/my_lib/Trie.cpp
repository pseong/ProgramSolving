const int MX = 10000 * 500 + 10;
int num = 1;
int chk[MX], nxt[MX][26];

void insert(string& s) {
    int cur = 1;
    for (char c : s) {
        int x = c - 'a';
        if (nxt[cur][x] == 0) {
            nxt[cur][x] = ++num;
        }
        cur = nxt[cur][x];
    }
    chk[cur] = 1;
}

bool find(string& s) {
    int cur = 1;
    for (int c : s) {
        int x = c - 'a';
        if (nxt[cur][x] == 0) return false;
        cur = nxt[cur][x];
    }
    return chk[cur];
}