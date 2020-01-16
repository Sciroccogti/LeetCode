/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// 12ms, 7.1MB

int lengthOfLongestSubstring(char* s) {
    if(*s == '\0'){
        return 0;
    }

    char *p = s+1, *head = s, *q;
    int i = 1, count = 1;

    while(*p){
        for(q = head; q < p; q++){
            if(*p == *q){
                head = q+1;
                break;
            }
            i++;
        }
        
        p++;
        if(i > count){
            count = i;
        }
        i = 1;
    }
    return count;
}


// @lc code=end

