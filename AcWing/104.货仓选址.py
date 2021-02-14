# 寒假每日一题（入门组）0109

import heapq
N = int(input())
A = []
Amax = []
for i in input().split():
    # A.append(int(input))
    heapq.heappush(A, int(i))
    heapq.heappush(Amax, -int(i))

dis = 0
for i in range(N//2):
    min = heapq.heappop(A)
    max = -heapq.heappop(Amax)
    dis += max - min

print(dis)

# 两个点：两点间任一点
# 三个点：中间那个点
# 四个点：中间两个点中间
# 五个点：中间那个点
