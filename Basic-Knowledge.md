# 基础知识

## C++语言基础

```Cpp
5 - 0.1; // 5 先变成浮点数，再与 0.1 计算
a || b; // 若 a 为 True，则不会计算 b 的值
```

算法竞赛中不要使用 `<conio.h>` 以及其中的 `getch(), clrscr()`，或者 `getche(), gotoxy()`

π 可以使用 `const double pi = acos(-1.0);` 获得

**Keep It Simple and Stupid**--KISS

`gets()` 在 C11 中被移除。

C89 即 ANSI C

浮点运算可能存在误差。
在进行浮点数比较时，应考虑到浮点误差。
常用四舍五入来优化。

譬如：
```Cpp
double i;
for (i = 0; i != 10; i += 0.1);
```
是一个死循环，因为误差累加，使得 i 最终为9.99999

### 大整数

2^31 = ‭2,147,483,648‬，约 2亿；
`<iostream>` 内有 `int32_t (%ld), int64_t (%I64d)`

大整数要注意中间步骤的溢出

> （大整数为什么不用香香的 Python 呢？）
> 
> 阿姨语：这边建议 [J A V A](https://doowzs.com/code/bzoj-1002/)

- Windows 平台：int64_t 对应 %I64d
- Linux 平台：int64_t 对应 %lld

### 计时

```Cpp
#include <time.h>
#include <stdio.h>
int main() {
    double t = (double)clock() / CLOCKS_PER_SEC;
	for (int i = 0; i < 100000000; i++);
	double t2 = (double)clock() / CLOCKS_PER_SEC;
    printf("%lf", t2 - t);
}
```

### 输出

不会怎么输出就用 `cout`

`printf()`：
- %d
- %u：无符号十进制
- %f
- %s
- %c
- %p
- %e：科学计数法的浮点数
- %x, %X：无符号十六进制
- %o：无符号八进制
- %g：自动

### 存储空间

**段**：
- 正文段：指令
- 数据段：已初始化的全局变量
- BSS 段：未初始化的全局变量
- 调用栈：与存储在二进制文件中的以上段不同，调用段在运行时创建的堆栈段中

因此，若数组较大，最好作为全局变量，就能避免栈溢出

### STL

```Cpp
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a[10], n = 10, x;
    sort(a, a+n);
    lower_bound(a, a+n, x); // 找到大于或等于 x 的第一个位置
    unique(a, a+n) // 去重
}
```

```Cpp
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <string>
using namespace std;
int main() {
    int a[3] = {1, 2, 3};
    set <int, greater<int>> dict(a, a + 3); // 不重复，默认从小到大
    map <string, int> cnt;
    stack <int> s;
}
```

## Python 基础

（非必需）函数要在开头定义，并且加上函数注释：
```Python
def myprint(text: str) -> int:
    "myprint!"
    print(text)
    return 0
```

## 数据结构

### 二叉树

用数组方式实现二叉树是算法竞赛常用方式，编程简单，容易调试

