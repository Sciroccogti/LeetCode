# 基础知识

## C++语言基础

```C++
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

### 大整数

2^31 = ‭2,147,483,648‬，约 2亿；
`<iostream>` 内有 `int32_t (%ld), int64_t (%I64d)`

大整数要注意中间步骤的溢出

> （大整数为什么不用香香的 Python 呢？）
> 阿姨语：

- Windows 平台：int64_t 对应 %I64d
- Linux 平台：int64_t 对应 %lld

### 计时

```C++
#include <time.h>
#include <stdio.h>
int main()
{
    double t = (double)clock() / CLOCKS_PER_SEC;
	for (int i = 0; i < 100000000; i++);
	double t2 = (double)clock() / CLOCKS_PER_SEC;
    printf("%lf", t2 - t);
}
```
