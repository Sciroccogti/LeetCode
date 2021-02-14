# OJ 奇技淫巧

动手前一定要数学化、模型化题目！

## 棋盘

用 `dx` `dy` 存储偏移量来减少冗余代码：
```cpp
// 若需判断上下左右块
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
for (int i = 0; i < 4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (Mat[a][b] == 0) {
        printf("haha!\n");
    }
}
```
