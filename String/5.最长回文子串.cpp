/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        string ret = s.substr(0, 1);
        // vector<char> char_stack;
        vector<int> record;
        char* p = &s[0];
        int max = 1;

        for (int i = 0; i < s.size(); i++) {
            // char_stack.push_back(p[i]);

            // query records
            for (vector<int>::iterator j = record.begin(); j != record.end();
                 j++) {
                if (*j == 0)
                {
                    continue;
                }
                
                if (i - *j - 1 >= 0 && p[i] == p[i - *j - 1]) {
                    *j += 2;
                } else {
                    *j = 0;
                    continue;
                }
                if (*j > max) {
                    max = *j;
                    ret = s.substr(i - max + 1, max);
                }
            }

            // new record
            if (i > 0 && p[i] == p[i - 1]) {
                record.push_back(2);
                if (2 > max) {
                    max = 2;
                    ret = s.substr(i - max + 1, max);
                }
            }
            if (i > 1 && p[i] == p[i - 2]) {
                record.push_back(3);
                if (3 > max) {
                    max = 3;
                    ret = s.substr(i - max + 1, max);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
int main() {
    Solution s;
    string input = "abacab";
    cout << "input: " << input << "\toutput: " << s.longestPalindrome(input)
         << endl;
}