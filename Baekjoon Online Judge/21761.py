import sys

input = sys.stdin.readline

n = 0
k = 0
val = [0, 0, 0, 0]
idx = [0, 0, 0, 0]
v = [[],[],[],[]]

n, k = map(int, input().split())
val[0], val[1], val[2], val[3] = map(int, input().split())

for i in range(n):
    c, p = input().split()
    c = ord(c)
    p = int(p)
    for j in range(4):
        if c == ord('A')+j:
             v[j].append(p)

for i in range(4):
    v[i].sort(reverse=True)

ans = []

for cnt in range(k):
    ans_idx = -1
    ans_cal = 0
    for i in range(4):
        if (idx[i] >= len(v[i])):
            continue
        val[i] += v[i][idx[i]]
        cal = val[0] * val[1] * val[2] * val[3]
        val[i] -= v[i][idx[i]]
        if cal > ans_cal:
            ans_idx = i
            ans_cal = cal
    val[ans_idx] += v[ans_idx][idx[ans_idx]]
    print(chr(ord('A')+ans_idx), v[ans_idx][idx[ans_idx]])
    idx[ans_idx] += 1