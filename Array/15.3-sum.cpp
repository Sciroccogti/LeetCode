/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        //vector<int> tmp;
        sort(nums.begin(), nums.end());//排序
        int i,j,k;
        i = 0;
        k = nums.size()-1;
        while(i<k-1){
            j = i+1;
            while(j<k){
                if(nums[k]>-(nums[i]+nums[j])){
                    k--;
                }
                else if(nums[k]<-(nums[i]+nums[j])){
                    j++;
                }
                else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(nums[k]==nums[k-1]&&j<k){
                        k--;
                    }
                    k--;
                }
            }
            while(nums[i]==nums[i+1]&&i<nums.size()-2){
                i++;
            }
            i++;
            k = nums.size()-1;//最后一个
        }
        return res;
    }
};
// @lc code=end
