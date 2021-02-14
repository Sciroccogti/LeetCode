# 寒假每日一题（入门组）0124

N = int(input())

start = 1

for i in range(N):
    start *= i+1
    while start % 10 == 0:
        start //= 10
    start = start % 1000

print(start % 10)
