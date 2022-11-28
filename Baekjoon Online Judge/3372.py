
n = int(input())
v = [[0 for i in range(n + 1)] for j in range(n + 1)]
v.append(0)
for i in range(1, n + 1):
    tmp = list(map(int, input().split()))
    for j in range(1, n + 1):
        v[i][j] = tmp[j - 1]
dp = [[0 for i in range(n + 1)] for j in range(n + 1)] 
dp[1][1] = 1
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if v[i][j] == 0: continue
        if i + v[i][j] <= n: dp[i + v[i][j]][j] += dp[i][j]
        if j + v[i][j] <= n: dp[i][j + v[i][j]] += dp[i][j]
print(dp[n][n])