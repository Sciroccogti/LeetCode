/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start

bool isMatch(char* s, char* p) {
    int len_s = strlen(s), len_p = strlen(p);
    if (!len_p || !len_s) {
        return false;
    }

    bool isPoint = false, isStar = false;
    char lastChar = ' ';
    int j = 0;
    for (size_t i = 0; i < len_p; i++) {
        if (p[i] == '.') {
            isPoint = true;
            isStar = false;
            lastChar = ' ';

        } else if (p[i] == '*') {
            isStar = true;

            while (j) {
                if (s[j] != lastChar && lastChar != ' ') {
                    i--;
                    
                } else if (s[j] != lastChar && lastChar == ' ') {

                }
                j++;
                if (j == len_s) {
                    return true;
                }
            }

        } else if (p[i] >= 'a' && p[i] <= 'z') {
            if (p[i] != s[j]) {
                return false;
            }

            isPoint = isStar = false;
            lastChar = s[j];
            j++;

            if (j == len_s) {
                return true;
            }
        }
    }
    return false;
}

// @lc code=end
int main() {
    char* s = "aa";
    char* p = "a*";
    printf("input: %s\t%s\noutput: %d\n", s, p, isMatch(s, p));
}
