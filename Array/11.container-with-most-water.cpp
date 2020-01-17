/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int res=0;
        int begin = 0,end =n-1;
        while(begin<end){
            res = max(min(height[begin],height[end])*(end-begin),res);
            if(height[begin]<height[end])begin++;
            else end--;
        }
        return res;
    }
};
// @lc code=end
