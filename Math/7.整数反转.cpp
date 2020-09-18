/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
   public:
    int reverse(int64_t x) {
        if (!x) {
            return 0;
        }

        bool isPositive = x >= 0;
        if (!isPositive) {
            x = -x;
        }

        std::vector<int8_t> bit;
        bool endwith0 = true;
        while (x >= 10) {
            if (x % 10 && endwith0) {
                endwith0 = false;
            }
            if (!endwith0) {
                bit.push_back(x % 10);
            }

            x /= 10;
        }

        bit.push_back(x);

        while (bit.size() && bit[bit.size() - 1] == 0) {
            bit.pop_back();
        }

        int ret = isPositive ? bit[0] : -bit[0];

        for (int i = 1; i < bit.size(); i++) {
            // overflow
            if (ret > INT32_MAX / 10 ||
                (ret == INT32_MAX / 10 && bit[i] == 8) ||
                ret < -214748364 ||
                (ret == -214748364 && bit[i] == 9)) {
                return 0;
            }

            ret *= 10;
            ret = isPositive ? ret + bit[i] : ret - bit[i];
        }

        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    // 2147483648    
    int input = -123;
    printf("input %d, output %d\n", input, s.reverse(input));
}