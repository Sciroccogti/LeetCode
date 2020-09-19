/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start

int myAtoi(char *str) {
    uint isPrefix = 1;
    uint isZero = 0;
    int sign = 0;
    int ret = 0;
    for (char *p = str; *p != '\0'; p++) {
        // end prefix
        if (isPrefix && *p != ' ') {
            if (!sign && *p == '+') {
                sign = 1;
            } else if (!sign && *p == '-') {
                sign = -1;
            } else if (*p > '9' || *p < '0') {
                return 0;
            } else if (*p == '0') {
                sign = 1;
                isZero = 1;
            } else {
                sign = 1;
                ret += *p - '0';
            }
            isPrefix = 0;
        }

        // end transform
        else if (!isPrefix) {
            if (*p > '9' || *p < '0') {
                break;
            } else if (!isZero) {
                // overflow
                if (ret * sign > 214748364 ||
                    (ret * sign == 214748364 && *p >= '8')) {
                    return 2147483647;
                } else if (ret * sign < -214748364 ||
                           (ret * sign == -214748364 && *p >= '8')) {
                    return -2147483648;
                }
                ret *= 10;
                ret += *p - '0';
            } else if (isZero && *p != '0') {
                isZero = 0;
                ret += *p - '0';
            }
        }
    }
    ret *= sign;
    return ret;
}

// @lc code=end
int main() {
    char *input = "2147483646";
    printf("input: %s, output: %d\n", input, myAtoi(input));
}
