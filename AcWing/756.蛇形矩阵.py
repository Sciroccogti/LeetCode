# 寒假每日一题（入门组）0111
# WA了四次。。。。

n, m = [int(i) for i in input().split()]

output = [[0]*m for _ in range(n)]

orient = 0  # 0：右，1: 下，2：左，3：上
length = m  # 同向长度
l = [m-2, n-1, m-1, n-2]

col = 0
row = 0

count = 0
for i in range(n*m):
    output[row][col] = i+1
    count += 1
    if count == length:
        count = 0
        orient += 1
        if orient > 3:
            orient = 0
        length = l[orient]
        l[orient] -= 2
    if orient == 0:
        col += 1
    elif orient == 1:
        row += 1
    elif orient == 2:
        col -= 1
    elif orient == 3:
        row -= 1

for i in range(n):
    for j in range(m):
        print(output[i][j], end="")
        if j == m-1:
            print()
        else:
            print(" ", end="")
