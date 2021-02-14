# 寒假每日一题（入门组）0110

n = int(input())
Max__ = []

# 添加第一行距离
Max__.append([int(input())])

# 从第二行开始循环
for i in range(n-1):
    # i 是行号-1
    Maxi_ = []
    count = 0
    for j in input().split():
        if count == 0:  # 每行第一个
            Maxi_.append(Max__[i][count] + int(j))
        elif count == i+1:  # 每行最后一个
            Maxi_.append(Max__[i][count-1] + int(j))
        else:
            Maxi_.append(max(Max__[i][count-1], Max__[i][count]) + int(j))
        count += 1
    Max__.append(Maxi_)

print(max(Max__[n-1]))
