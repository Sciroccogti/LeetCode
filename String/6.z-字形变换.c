/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start

char* convert(char* s, int numRows) {
    int len = strlen(s);
    int sets = ceil(len / (numRows * 2.0 - 2.0));
    int numCols = sets * (numRows - 1);
    if (!numCols) {
        return s;
    }

    char map[numCols][numRows];
    for (size_t i = 0; i < numRows; i++) {
        for (size_t j = 0; j < numCols; j++) {
            map[j][i] = ' ';
        }
    }
    int col = 0, row = 0;
    uint isTail = 0;
    for (size_t i = 0; i < len; i++) {
        map[col][row] = s[i];

        if (isTail && row == 0) {
            isTail = 0;
        }

        if (row == numRows - 1) {
            isTail = 1;
        }

        if (!isTail) {
            row++;
        } else {
            row--;
            col++;
        }
    }

    char* p = s;
    for (size_t i = 0; i < numRows; i++) {
        for (size_t j = 0; j < numCols; j++) {
            if (map[j][i] != ' ') {
                *p = map[j][i];
                p++;
            }
        }
    }

    return s;
}

// @lc code=end
int main() {
    char input[1] = "A";
    int n = 1;
    printf("s = %s, numRows = %d\noutput: %s\n", input, n, convert(input, n));
}
