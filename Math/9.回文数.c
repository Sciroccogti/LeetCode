/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start

bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    
    char s[20];
    uint len = sprintf(s, "%d", x);
    for (size_t i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

// @lc code=end
int main() {
    int input = 0;
    printf("input: %d, output: %d\n", input, isPalindrome(input));
}
